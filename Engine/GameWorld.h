#pragma once

#include "GameObject.h"

namespace CustomEngine
{
	class GameWorld
	{
	private:
		GameWorld() {}
		~GameWorld() {}

		GameWorld(GameWorld const&) = delete;
		GameWorld& operator= (GameWorld const&) = delete;

		std::vector<GameObject*> gameObjects = {};
		std::vector<GameObject*> markedToDestroyGameObjects = {};

		void destroyGameObjectImmediate(GameObject* gameObject);

	public:
		static GameWorld* getInstance();

		void update(float deltaTime);
		void render();
		void lateUpdate();

		GameObject* createGameObject();
		GameObject* createGameObject(std::string name);
		void destroyGameObject(GameObject* gameObject);
		void clear();
	};
}