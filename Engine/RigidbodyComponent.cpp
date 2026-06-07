#include "pch.h"

#include "RigidbodyComponent.h"

namespace CustomEngine
{
	RigidbodyComponent::RigidbodyComponent(GameObject* ptrGameObject) : Component(ptrGameObject)
	{
		transform = ptrGameObject->getComponent<TransformComponent>();
	}

	void RigidbodyComponent::setLinearVelocity(Vector2Df newLinearVelocity)
	{
		linearVelocity = newLinearVelocity;
	}

	void RigidbodyComponent::addLinearVelocity(Vector2Df linearOffset)
	{
		linearVelocity = linearVelocity + linearOffset;
	}

	Vector2Df RigidbodyComponent::getLinearVelocity() const
	{
		return linearVelocity;
	}

	void RigidbodyComponent::setAngleVelocity(float newAngleVelocity)
	{
		angleVelocity = newAngleVelocity;
	}

	void RigidbodyComponent::addAngleVelocity(float angleOffset)
	{
		angleVelocity += angleOffset;
	}

	float RigidbodyComponent::getAngleVelocity() const
	{
		return angleVelocity;
	}

	void RigidbodyComponent::setLinearDamping(float newLinearDamping)
	{
		linearDamping = newLinearDamping;
	}

	float RigidbodyComponent::getLinearDamping() const
	{
		return linearDamping;
	}

	void RigidbodyComponent::setAngleDamping(float newAngleDamping)
	{
		angleDamping = newAngleDamping;
	}

	float RigidbodyComponent::getAngleDamping() const
	{
		return angleDamping;
	}

	void RigidbodyComponent::setKinematic(bool newIsKinematic)
	{
		isKinematic = newIsKinematic;
	}

	bool RigidbodyComponent::getKinematic() const
	{
		return isKinematic;
	}

	void RigidbodyComponent::update(float deltaTime)
	{
		transform->moveBy(linearVelocity);
		transform->rotateBy(angleVelocity);

		linearVelocity = (1.f - linearDamping * deltaTime) * linearVelocity;
		angleVelocity = (1.f - angleDamping * deltaTime) * angleVelocity;

		if (linearVelocity.x < 0.001f)
		{
			linearVelocity = { 0.f, linearVelocity.y };
		}
		if (linearVelocity.y < 0.001f)
		{
			linearVelocity = { linearVelocity.x, 0.f };
		}

		if (angleVelocity < 0.001f)
		{
			angleVelocity = 0.f;
		}
	}
	void RigidbodyComponent::render()
	{

	}
}