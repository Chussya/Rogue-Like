#include "DeveloperLevel.h"

using namespace CustomEngine;

namespace RoguelikeGame
{
	void DeveloperLevel::start()
	{
		int width = 15;
		int height = 15;

		for (int y = 0; y < height + 1; y++)
		{
			for (int x = 0; x < width + 1; x++)
			{
				//if not wall place
				if (x != 0 && x != width && y != 0 && y != height)
				{
					floors.push_back(std::make_unique<Floor>(std::forward<CustomEngine::Vector2Df>({ x * 128.f, y * 128.f })));
				}

				//if left-bottom corner
				if (x == 0 && y == 0)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<CustomEngine::Vector2Df>({ x * 128.f, y * 128.f })));
				}

				//if right-bottom corner
				if (x == width && y == 0)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<CustomEngine::Vector2Df>({ x * 128.f, y * 128.f })));
				}

				//if left-top corner
				if (x == 0 && y == height)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<CustomEngine::Vector2Df>({ x * 128.f, y * 128.f })));
				}

				//if right-top corner
				if (x == width && y == height)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<CustomEngine::Vector2Df>({ x * 128.f, y * 128.f })));
				}

				//if left (not corner)
				if (x == 0 && y != height && y != 0)
				{
					floors.push_back(std::make_unique<Floor>(std::forward<CustomEngine::Vector2Df>({ x * 128.f, y * 128.f })));
					walls.push_back(std::make_unique<Wall>(std::forward<CustomEngine::Vector2Df>({ x * 128.f, y * 128.f })));
				}

				//if right (not corner)
				if (x == width && y != height && y != 0)
				{
					floors.push_back(std::make_unique<Floor>(std::forward<CustomEngine::Vector2Df>({ x * 128.f, y * 128.f })));
					walls.push_back(std::make_unique<Wall>(std::forward<CustomEngine::Vector2Df>({ x * 128.f, y * 128.f })));
				}

				//if bottom (not corner)
				if (y == 0 && x != width && x != 0)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<CustomEngine::Vector2Df>({ x * 128.f, y * 128.f })));
				}

				//if top (not corner)
				if (y == height && x != width && x != 0)
				{
					walls.push_back(std::make_unique<Wall>(std::forward<CustomEngine::Vector2Df>({ x * 128.f, y * 128.f })));
				}
			}
		}
		player = std::make_shared<Player>(std::forward<CustomEngine::Vector2Df>({ width / 2 * 128.f, height / 2 * 128.f }));
		enemy = std::make_shared<Enemy>(std::forward<CustomEngine::Vector2Df>({ width / 3 * 128.f, height / 3 * 128.f }), player->getGameObject());
		music = std::make_unique<CustomMusic>("m_dungeonAmb");
	}

	void DeveloperLevel::restart()
	{
		stop();
		start();
	}

	void DeveloperLevel::stop()
	{
		GameWorld::getInstance()->clear();
	}
}