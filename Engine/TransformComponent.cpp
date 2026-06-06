#include "pch.h"

#include "TransformComponent.h"

namespace CustomEngine
{
	TransformComponent::TransformComponent(GameObject* ptrGameObject) : Component(ptrGameObject) {}

	void TransformComponent::moveBy(const Vector2Df & offset)
	{
		pos.x += offset.x;
		pos.y += offset.y;
	}

	void TransformComponent::scaleBy(const Vector2Df & scaleOffset)
	{
		scale.x *= scaleOffset.x;
		scale.y *= scaleOffset.y;
	}

	void TransformComponent::rotateBy(const float offset)
	{
		rotation = rotation + offset;

		while (rotation >= 360)
		{
			rotation -= 360;
		}
		while (rotation < 0)
		{
			rotation += 360;
		}
	}

	const Vector2Df TransformComponent::getWorldPosition() const
	{
		return pos;
	}

	const Vector2Df TransformComponent::getWorlScale() const
	{
		return scale;
	}

	const float TransformComponent::getWorldRotation() const
	{
		return rotation;
	}

	void TransformComponent::update(float deltaTime)
	{}

	void TransformComponent::render()
	{}
}
