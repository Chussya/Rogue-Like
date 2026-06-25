#include "pch.h"

#include "MovementComponent.h"

namespace CustomEngine
{
	MovementComponent::MovementComponent(GameObject* gameObject) : Component(gameObject)
	{
		input = gameObject->getComponent<InputComponent>();
		transform = gameObject->getComponent<TransformComponent>();

		if (input == nullptr)
		{
			std::cout << "Need input component for movement" << std::endl;
			gameObject->removeComponent(this);
		}
	}

	void MovementComponent::setSpeed(float speed)
	{
		this->speed = speed;
	}

	float MovementComponent::getSpeed() const
	{
		return speed;
	}

	float MovementComponent::getAccelerationSquared() const
	{
		return acceleration.x * acceleration.x + acceleration.y * acceleration.y;
	}

	void MovementComponent::update(float deltaTime)
	{
		float xAxis = input->getHorizontalAxis();
		float yAxis = input->getVerticalAxis();

		transform->moveBy(speed * deltaTime * Vector2Df{ xAxis, yAxis });

		acceleration = transform->getWorldPosition() - previousPosition;
		previousPosition = transform->getWorldPosition();
	}

	void MovementComponent::render() {}
}
