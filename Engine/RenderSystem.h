#pragma once

#include <SFML/Graphics.hpp>

namespace CustomEngine
{
	class RenderSystem
	{
	private:
		sf::RenderWindow* window;

		RenderSystem(){}
		~RenderSystem(){}

		RenderSystem(RenderSystem const&) = delete;
		RenderSystem& operator= (RenderSystem const&) = delete;

	public:
		static RenderSystem* getInstance();

		void setMainWindow(sf::RenderWindow* window);
		sf::RenderWindow& getMainWindow() const;

		void render(const sf::Drawable& drawable);
	};
}

