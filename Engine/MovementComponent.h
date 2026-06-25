#pragma once

#include "GameObject.h"
#include "InputComponent.h"

namespace CustomEngine
{
	class MovementComponent : public Component
	{
	private:
		InputComponent* input;
		TransformComponent* transform;

		float speed{ 0 };
		Vector2Df previousPosition = { 0, 0 };
		Vector2Df acceleration = { 0, 0 };

	public:
		MovementComponent(GameObject* ptrGameObject);

		void setSpeed(float speed);
		float getSpeed() const;
		float getAccelerationSquared() const;

		// Inherited via Component
		void update(float deltaTime) override;
		void render() override;
	};
}