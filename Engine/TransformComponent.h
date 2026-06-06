#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "Component.h"
#include "GameObject.h"
#include "Vector2D.h"

namespace CustomEngine
{
	class TransformComponent : public Component
	{
	private:
		mutable Vector2Df pos{ 0, 0 };
		mutable float rotation{ 0.f };
		mutable Vector2Df scale{ 1, 1 };

	public:
		TransformComponent(GameObject* ptrGameObject);

		void moveBy(const Vector2Df& offset);
		void scaleBy(const Vector2Df& scaleOffset);
		void rotateBy(const float offset);

		const Vector2Df getWorldPosition() const;
		const Vector2Df getWorlScale() const;
		const float getWorldRotation() const;

		// Inherited via Component
		void update(float deltaTime) override;
		void render() override;
	};
}

