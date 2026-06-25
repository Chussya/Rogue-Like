#pragma once

#include "GameObject.h"
#include "InputComponent.h"
#include "SpriteRendererComponent.h"

namespace CustomEngine
{
	class SpriteDirectionComponent : public Component
	{
	private:
		InputComponent* input;
		SpriteRendererComponent* spriteRenderer;

	public:
		SpriteDirectionComponent(GameObject* ptrGameObject);

		void update(float deltaTime) override;
		void render() override;
	};
}
