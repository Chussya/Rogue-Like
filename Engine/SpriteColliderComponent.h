#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "ColliderComponent.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"

namespace CustomEngine
{
	class SpriteColliderComponent : public ColliderComponent
	{
	private:
		const sf::Sprite* sprite;

	public:
		SpriteColliderComponent(GameObject* gameObject);
		~SpriteColliderComponent();

		void update(float deltaTime) override;
		void render() override;
	};
}