#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Engine.h"
#include "ResourceSystem.h"
#include "LevelManager.h"

using namespace RoguelikeGame;

int main()
{
	CustomEngine::RenderSystem::getInstance()->setMainWindow(new sf::RenderWindow(sf::VideoMode(1280, 720), "Roguelike"));

	CustomEngine::ResourceSystem::getInstance()->loadTexture("txtr_player", "Resources/Image/upd-player.png");
	CustomEngine::ResourceSystem::getInstance()->loadTexture("txtr_enemy", "Resources/Image/enemy.png");
	CustomEngine::ResourceSystem::getInstance()->loadTexture("txtr_floor", "Resources/Image/floor.png");
	CustomEngine::ResourceSystem::getInstance()->loadTexture("txtr_wall", "Resources/Image/wall.png");
	CustomEngine::ResourceSystem::getInstance()->loadSound("m_dungeonAmb", "Resources/Audio/Music/dungeon_ambience.ogg");

	LevelManager::getInstance()->loadLevel();

	CustomEngine::Engine::getInstance()->run();

	return 0;
}