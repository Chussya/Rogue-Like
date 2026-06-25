#include "pch.h"

#include "SpriteColliderComponent.h"

namespace CustomEngine
{
	SpriteColliderComponent::SpriteColliderComponent(GameObject* gameObject) : ColliderComponent(gameObject)
	{
		auto spriteRenderer = gameObject->getComponent<SpriteRendererComponent>();
		if (spriteRenderer == nullptr)
		{
			std::cout << "SpriteRenderer required to SpriteCollider." << std::endl;
			gameObject->removeComponent(this);
			return;
		}

		sprite = gameObject->getComponent<SpriteRendererComponent>()->getSprite();
		PhysicsSystem::getInstance()->subscribe(this);
	}

	SpriteColliderComponent::~SpriteColliderComponent()
	{
		if (&bounds != nullptr)
		{
			std::destroy_at(&bounds);
		}
		PhysicsSystem::getInstance()->unsubscribe(this);
	}

	void SpriteColliderComponent::update(float deltaTime)
	{
		bounds = sprite->getGlobalBounds();
	}
	void SpriteColliderComponent::render()
	{
		sf::RectangleShape rectangle(sf::Vector2f(bounds.width, bounds.height));
		rectangle.setPosition(bounds.left, bounds.top);
		rectangle.setFillColor(sf::Color::Transparent);
		rectangle.setOutlineColor(sf::Color::White);
		rectangle.setOutlineThickness(4);

		RenderSystem::getInstance()->render(rectangle);
	}
}