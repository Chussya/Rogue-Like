#include "pch.h"
#include "Engine.h"
#include <iostream>
#include "GameWorld.h"
#include "RenderSystem.h"

namespace CustomEngine
{
	// Private

	Engine::Engine()
	{
		unsigned int seed = (unsigned int)time(nullptr);
		srand(seed);
	}

	// Public

	Engine* Engine::getInstance()
	{
		static Engine instance;

		return &instance;
	}

	void Engine::run()
	{
		sf::Clock gameClock;
		sf::Event event;

		while (RenderSystem::getInstance()->getMainWindow().isOpen())
		{
			sf::Time dt = gameClock.restart();
			float deltaTime = dt.asSeconds();

			while (RenderSystem::getInstance()->getMainWindow().pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					RenderSystem::getInstance()->getMainWindow().close();
				}
			}

			if (!RenderSystem::getInstance()->getMainWindow().isOpen())
			{
				break;
			}

			RenderSystem::getInstance()->getMainWindow().clear();

			GameWorld::getInstance()->update(deltaTime);
			GameWorld::getInstance()->fixedUpdate(deltaTime);
			GameWorld::getInstance()->render();
			GameWorld::getInstance()->lateUpdate();

			RenderSystem::getInstance()->getMainWindow().display();
		}
	}
}