#include "pch.h"
#include "GameWorld.h"

namespace CustomEngine
{
	// Private

	void GameWorld::destroyGameObjectImmediate(GameObject* gameObject)
	{
		auto parent = gameObject->getComponent<TransformComponent>()->getParent();
		if (parent != nullptr)
		{
			parent->getGameObject()->removeChild(gameObject);
		}

		for (auto transform : gameObject->getComponentsInChildren<TransformComponent>())
		{
			GameObject* gameObjectToDelete = transform->getGameObject();

			gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [gameObjectToDelete](GameObject* obj) { return obj == gameObjectToDelete; }), gameObjects.end());
			markedToDestroyGameObjects.erase(std::remove_if(markedToDestroyGameObjects.begin(), markedToDestroyGameObjects.end(), [gameObjectToDelete](GameObject* obj) { return obj == gameObjectToDelete; }), markedToDestroyGameObjects.end());

			delete gameObjectToDelete;
		}
	}

	// Public

	GameWorld* GameWorld::getInstance()
	{
		static GameWorld world;
		return &world;
	}

	void GameWorld::update(float deltaTime)
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->update(deltaTime);
		}
	}

	void GameWorld::fixedUpdate(float deltaTime)
	{
		fixedCounter += deltaTime;
		if (fixedCounter > PhysicsSystem::getInstance()->getFixedDeltaTime())
		{
			fixedCounter -= PhysicsSystem::getInstance()->getFixedDeltaTime();
			PhysicsSystem::getInstance()->update();
		}
	}

	void GameWorld::render()
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->render();
		}
	}
	void GameWorld::lateUpdate()
	{
		for (int i = markedToDestroyGameObjects.size() - 1; i >= 0; i--)
		{
			destroyGameObjectImmediate(markedToDestroyGameObjects[i]);
		}
	}

	GameObject* GameWorld::createGameObject()
	{
		GameObject* newGameObject = new GameObject();
		gameObjects.push_back(newGameObject);
		return newGameObject;
	}

	GameObject* GameWorld::createGameObject(std::string name)
	{
		GameObject* newGameObject = new GameObject(name);
		gameObjects.push_back(newGameObject);
		return newGameObject;
	}

	void GameWorld::destroyGameObject(GameObject* gameObject)
	{
		markedToDestroyGameObjects.push_back(gameObject);
	}

	void GameWorld::clear()
	{
		for (int i = gameObjects.size() - 1; i >= 0; i--)
		{
			if (gameObjects[i] == nullptr)
			{
				continue;
			}

			if (gameObjects[i]->getComponent<TransformComponent>()->getParent() == nullptr)
			{
				destroyGameObjectImmediate(gameObjects[i]);
			}
		}
		fixedCounter = 0.f;
	}

	void GameWorld::print() const
	{
		for (auto& obj : gameObjects)
		{
			if (obj == nullptr)
			{
				continue;
			}
			if (obj->getComponent<TransformComponent>()->getParent() == nullptr)
			{
				obj->print();
			}
		}
	}
}