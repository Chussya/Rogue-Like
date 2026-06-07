#pragma once

#include "GameObject.h"
#include "PhysicsSystem.h"

namespace CustomEngine
{
	class GameWorld
	{
	private:
		float fixedCounter{ 0.f };
		std::vector<GameObject*> gameObjects = {};
		std::vector<GameObject*> markedToDestroyGameObjects = {};

		GameWorld() {}
		~GameWorld() {}

		GameWorld(GameWorld const&) = delete;
		GameWorld& operator= (GameWorld const&) = delete;

		void destroyGameObjectImmediate(GameObject* gameObject);

	public:
		static GameWorld* getInstance();

		void update(float deltaTime);
		void fixedUpdate(float deltaTime);
		void render();
		void lateUpdate();

		GameObject* createGameObject();
		GameObject* createGameObject(std::string name);
		void destroyGameObject(GameObject* gameObject);
		void clear();

		void print() const;
	};
}