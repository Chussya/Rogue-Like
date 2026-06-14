#include "pch.h"

#include "FollowComponent.h"

namespace CustomEngine
{
	FollowComponent::FollowComponent(GameObject* gameObject) : Component(gameObject)
	{
		transform = gameObject->getComponent<TransformComponent>();
		spriteRender = gameObject->getComponent<SpriteRendererComponent>();

		if (transform == nullptr)
		{
			gameObject->removeComponent(this);
		}
	}

	void FollowComponent::setTarget(GameObject* target)
	{
		if (target)
		{
			targetTransform = target->getComponent<TransformComponent>();
		}
	}

	void FollowComponent::setSpeed(const float speed)
	{
		this->speed = speed;
	}

	float FollowComponent::getSpeed() const
	{
		return speed;
	}

	void FollowComponent::update(float deltaTime)
	{
		if (transform == nullptr || targetTransform == nullptr)
		{
			return;
		}

		Vector2Df currentPos = transform->getWorldPosition();
		Vector2Df targetPos = targetTransform->getWorldPosition();
		Vector2Df directionPos = targetPos - currentPos;

		float length = directionPos.getLength();

		if (length > 0.001f)
		{
			Vector2Df normalized = Vector2Df(directionPos.x / length, directionPos.y / length);
			transform->moveBy(normalized * speed * deltaTime);

			if (spriteRender)
			{
				spriteRender->flipX(directionPos.x < 0);
			}
		}
	}

	void FollowComponent::render(){}
}
