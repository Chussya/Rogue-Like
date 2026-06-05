#pragma once

#include "GameStateData.h"

namespace RoguelikeGame
{
	class GameStateMainMenuData : public GameStateData
	{
	private:
		/// Fonts

		sf::Font font;

		/// Texts

		sf::Text title;

	public:
		GameStateMainMenuData() = default;
		~GameStateMainMenuData() = default;

		void init() override;
		void handleWindowEvent(const sf::Event& event) override;
		void draw(sf::RenderWindow& window) override;
		void update(float deltaTime) override;
	};
}