#include "pch.h"

#include "SpriteDirectionComponent.h"

namespace CustomEngine
{
	SpriteDirectionComponent::SpriteDirectionComponent(GameObject* ptrGameObject) : Component(ptrGameObject)
	{
		input = ptrGameObject->getComponent<InputComponent>();
		spriteRenderer = ptrGameObject->getComponent<SpriteRendererComponent>();
	}

	void SpriteDirectionComponent::update(float deltaTime)
	{
		if (input->getHorizontalAxis() < 0)
		{
			spriteRenderer->flipX(true);
		}
		if (input->getHorizontalAxis() > 0)
		{
			spriteRenderer->flipX(false);
		}
	}

	void SpriteDirectionComponent::render() {}
}
