#pragma once

// This block necessary for export to another projects
#ifdef ENGINE_EXPORTS
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif // ENGINE_EXPORTS

#include <SFML/Graphics.hpp>

#include "Vector2D.h"

namespace CustomEngine
{
	class ENGINE_API GameObject
	{
	protected:
		sf::Sprite sprite;
		sf::Texture texture;

	public:
		GameObject(const std::string& textureId, const Vector2Df& position, float width, float height);
		virtual ~GameObject() = default;

		// Getters

		virtual Vector2Df getPosition() const;
		virtual sf::FloatRect getRect() const;

		// Standard virtual methods

		virtual void update(const float) = 0;
		virtual void drawOnWindow(sf::RenderWindow&);

		// General methods

		virtual void setSpriteOrigin(const float originX, const float originY);
		virtual void updateSpriteSize(const float width, const float height);
	};
}