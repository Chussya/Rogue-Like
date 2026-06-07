#pragma once

#include "TransformComponent.h"
#include "Vector2D.h"

namespace CustomEngine
{
	class RigidbodyComponent : public Component
	{
	private:
		TransformComponent* transform;

		Vector2Df linearVelocity = { 0.f, 0.f };
		float angleVelocity{ 0.f };

		float linearDamping{ 0.f };
		float angleDamping{ 0.f };

		bool isKinematic{ false };

	public:
		RigidbodyComponent(GameObject* ptrGameObject);

		void setLinearVelocity(Vector2Df newLinearVelocity);
		void addLinearVelocity(Vector2Df linearOffset);
		Vector2Df getLinearVelocity() const;

		void setAngleVelocity(float newAngleVelocity);
		void addAngleVelocity(float angleOffset);
		float getAngleVelocity() const;

		void setLinearDamping(float newLinearDamping);
		float getLinearDamping() const;

		void setAngleDamping(float newAngleDamping);
		float getAngleDamping() const;

		void setKinematic(bool newIsKinematic);
		bool getKinematic() const;

		void update(float deltaTime) override;
		void render() override;
	};
}