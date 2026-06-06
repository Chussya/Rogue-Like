#include "pch.h"

#include "RenderSystem.h"

namespace CustomEngine
{
	RenderSystem* RenderSystem::getInstance()
	{
		static RenderSystem instance;

		return &instance;
	}

	void RenderSystem::setMainWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	sf::RenderWindow& RenderSystem::getMainWindow() const
	{
		return *window;
	}

	void RenderSystem::render(const sf::Drawable& drawable)
	{
		window->draw(drawable);
	}
}