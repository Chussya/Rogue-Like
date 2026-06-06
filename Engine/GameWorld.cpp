#include "pch.h"
#include "GameWorld.h"

namespace CustomEngine
{
	GameWorld* GameWorld::getInstance()
	{
		static GameWorld world;
		return &world;
	}

	void GameWorld::lateUpdate()
	{
		for (int i = static_cast<int>(markedToDestroyGameObjects.size() - 1); i >= 0; i--)
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

	void GameWorld::destroyGameObject(GameObject* gameObject)
	{
		markedToDestroyGameObjects.push_back(gameObject);
	}

	void GameWorld::clear()
	{
		for (int i = static_cast<int>(gameObjects.size() - 1); i >= 0; i--)
		{
			destroyGameObjectImmediate(gameObjects[i]);
		}
	}

	void GameWorld::destroyGameObjectImmediate(GameObject* gameObject)
	{
		gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(), [gameObject](GameObject* obj) { return obj == gameObject; }), gameObjects.end());
		markedToDestroyGameObjects.erase(std::remove_if(markedToDestroyGameObjects.begin(), markedToDestroyGameObjects.end(), [gameObject](GameObject* obj) { return obj == gameObject; }), markedToDestroyGameObjects.end());

		delete gameObject;
	}

	void GameWorld::update(float deltaTime)
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->update(deltaTime);
		}
	}

	void GameWorld::render()
	{
		for (int i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->render();
		}
	}
}