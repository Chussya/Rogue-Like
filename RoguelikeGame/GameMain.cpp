#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Engine.h"
#include "ResourceSystem.h"
#include "DeveloperLevel.h"

using namespace RoguelikeGame;

int main()
{
	CustomEngine::RenderSystem::getInstance()->setMainWindow(new sf::RenderWindow(sf::VideoMode(1280, 720), "XYZRoguelike"));

	CustomEngine::ResourceSystem::getInstance()->loadTexture("ball", "Resources/Image/orange.png");

	auto developerLevel = std::make_shared<DeveloperLevel>();
	developerLevel->start();

	CustomEngine::Engine::getInstance()->run();

	return 0;
}