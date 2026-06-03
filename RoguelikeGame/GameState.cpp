#include "GameState.h"

#include <cassert>

#include "Game.h"
#include "GameStateMainMenu.h"

namespace RoguelikeGame
{
	GameState::GameState(EGameStateType type, bool isExclusivelyVisible) : type{type}, isExclusivelyVisible{ isExclusivelyVisible }
	{
		switch (type)
		{
		case EGameStateType::MainMenu:
		{
			data = std::make_unique<GameStateMainMenuData>();
			break;
		}
		default:
			assert(false);
			break;
		}
		if (data)
		{
			data->init();
		}
	}

	GameState::~GameState()
	{
		data = nullptr;
	}

	EGameStateType GameState::getType() const
	{
		return type;
	}

	bool GameState::isVisible()
	{
		return isExclusivelyVisible;
	}

	void GameState::handleWindowEvent(sf::Event& event)
	{
		data->handleWindowEvent(event);
	}

	void GameState::update(float deltaTime)
	{
		data->update(deltaTime);
	}

	void GameState::draw(sf::RenderWindow& window)
	{
		data->draw(window);
	}
}