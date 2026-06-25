#pragma once

#include<SFML/Graphics.hpp>
#include<memory>

#include "TransformComponent.h"
#include "Vector2D.h"

namespace CustomEngine
{
	class SpriteRendererComponent : public Component
	{
	private:
		bool isFlipX{ false };
		bool isFlipY{ false };

		Vector2Df scale;
		sf::Sprite* sprite;
		TransformComponent* transform;

	public:
		SpriteRendererComponent(GameObject* ptrGameObject);
		~SpriteRendererComponent();

		const sf::Sprite* getSprite() const;
		void setTexture(const sf::Texture& texture);
		void setPixelSize(const int width, const int height);

		void flipX(bool flip);
		void flipY(bool flip);

		void update(float deltaTime) override;
		void render() override;
	};
}

