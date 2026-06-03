#include "GameStateMainMenu.h"

#include <cassert>

#include "Util.h"
#include "MenuItem.h"
#include "Application.h"
#include "GameSettings.h"

namespace RoguelikeGame
{
	void GameStateMainMenuData::handleWindowEvent(const sf::Event& event)
	{
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				Application::getInstance().getGame().quitGame();
			}
		}
	}

	void GameStateMainMenuData::init()
	{
		// Init Fonts

		assert(font.loadFromFile(GAME_SETTINGS.FONT_PATH + "Roboto-Light.ttf"));

		// Init Texts

		Util::UGraphic::initText(title, "TO BE DONE... Press Esc to exit to menu", font, sf::Color::Yellow, 40);
		Util::UGraphic::setItemOrigin(title, 0.5f, 0.5f);
	}

	void GameStateMainMenuData::draw(sf::RenderWindow& window)
	{
		float yCoordinate = 30.f;

		// Draw title
		title.setPosition(window.getSize().x / 2.f, yCoordinate);
		window.draw(title);
	}

	void GameStateMainMenuData::update(float deltaTime)
	{
	}
}