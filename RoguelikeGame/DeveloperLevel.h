#pragma once

#include <iostream>
#include <array>

#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Floor.h"
#include "Wall.h"
#include "CustomMusic.h"

using namespace CustomEngine;

namespace RoguelikeGame
{
	class DeveloperLevel : public Scene
	{
	private:
		std::shared_ptr<CustomMusic> music;
		std::shared_ptr<Player> player;
		std::shared_ptr<Enemy> enemy;
		std::vector<std::unique_ptr<Floor>> floors;
		std::vector<std::unique_ptr<Wall>> walls;

	public:
		// getters and setters

		std::vector<std::unique_ptr<Floor>>& getFloors();

		// core methods

		void start() override;
		void restart() override;
		void stop() override;

		// additional methods

		void createSpawner();
	};
}