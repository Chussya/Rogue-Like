#pragma once

#include "Component.h"
#include "TransformComponent.h"
#include "SpriteRendererComponent.h"

namespace CustomEngine
{
	class FollowComponent : public Component
	{
	private:
		TransformComponent* transform{ nullptr };
		TransformComponent* targetTransform{ nullptr };
		SpriteRendererComponent* spriteRender{ nullptr };

		float speed{ 100.f };

	public:
		FollowComponent(GameObject* gameObject);

		void setHeroAsTarget();
		void setTarget(GameObject* traget);
		void setSpeed(const float speed);
		float getSpeed() const;

		// Inherited via Component
		void update(float deltaTime) override;
		void render() override;
	};
}
