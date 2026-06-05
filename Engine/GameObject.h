#pragma once

#include <SFML/Graphics.hpp>

#include "Vector2D.h"

namespace CustomEngine
{
	class GameObject
	{
	protected:
		sf::Sprite sprite;
		sf::Texture texture;

	public:
		__declspec(dllexport) GameObject(const std::string& textureId, const Vector2Df& position, float width, float height);
		__declspec(dllexport) virtual ~GameObject() = default;

		// Getters

		__declspec(dllexport) virtual Vector2Df getPosition() const;
		__declspec(dllexport) virtual sf::FloatRect getRect() const;

		// Standard virtual methods

		__declspec(dllexport) virtual void update(const float) = 0;
		__declspec(dllexport) virtual void drawOnWindow(sf::RenderWindow&);

		// General methods

		__declspec(dllexport) virtual void setSpriteOrigin(const float originX, const float originY);
		__declspec(dllexport) virtual void updateSpriteSize(const float width, const float height);
	};
}