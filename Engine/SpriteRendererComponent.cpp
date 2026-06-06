#include "pch.h"

#include "SpriteRendererComponent.h"

#include "TransformComponent.h"
#include "RenderSystem.h"

namespace CustomEngine
{
	SpriteRendererComponent::SpriteRendererComponent(GameObject* ptrGameObject) : Component(ptrGameObject)
	{
		sprite = new sf::Sprite();
		sprite->setScale({ 1, -1 });

		transform = ptrGameObject->getComponent<TransformComponent>();
	}

	SpriteRendererComponent::~SpriteRendererComponent()
	{
		if (sprite != nullptr)
		{
			delete sprite;
		}
	}

	const sf::Sprite* SpriteRendererComponent::getSprite() const
	{
		return sprite;
	}

	void SpriteRendererComponent::setTexture(const sf::Texture& texture)
	{
		sprite->setTexture(texture);

		auto textureSize = sprite->getTexture()->getSize();
		sprite->setOrigin({ 0.5f * textureSize.x, 0.5f * textureSize.y });
	}

	void SpriteRendererComponent::setPixelSize(const int width, const int height)
	{
		auto originalSize = sprite->getTexture()->getSize();
		sprite->setScale(static_cast<float>(width) / static_cast<float>(originalSize.x), -static_cast<float>(height) / static_cast<float>(originalSize.y));
	}

	void SpriteRendererComponent::flipX(bool flip)
	{
		if (flip != isFlipX)
		{
			auto scale = sprite->getScale();
			sprite->setScale({ -scale.x, scale.y });
			isFlipX = flip;
		}
	}

	void SpriteRendererComponent::flipY(bool flip)
	{
		if (flip != isFlipY)
		{
			auto scale = sprite->getScale();
			sprite->setScale({ scale.x, -scale.y });
			isFlipY = flip;
		}
	}

	void SpriteRendererComponent::update(float deltaTime)
	{}

	void SpriteRendererComponent::render()
	{
		if (sprite != nullptr)
		{
			sprite->setPosition(convert<sf::Vector2f, Vector2Df>(transform->getWorldPosition()));
			sprite->setRotation(transform->getWorldRotation());
			RenderSystem::getInstance()->render(*sprite);
		}
	}
}
