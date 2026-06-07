#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "GameObject.h"
#include "Vector2D.h"
#include "Matrix2D.h"

namespace CustomEngine
{
	class TransformComponent : public Component
	{
	private:
		TransformComponent* ptrParent{ nullptr };

		mutable Matrix2D localTransform;
		mutable bool isUpdated{ false };

		mutable Vector2Df localPos{ 0, 0 };
		mutable float localRot{ 0.f };
		mutable Vector2Df localScale{ 1, 1 };

		mutable Vector2Df pos{ 0, 0 };
		mutable float rot{ 0.f };
		mutable Vector2Df scale{ 1, 1 };

		void setWorldInfoFrom(const Matrix2D& transform) const;
		void setLocalInfoFrom(const Matrix2D& transform) const;
		void updateLocalTransform() const;
		void updateLocalTransform(const Vector2Df& position, float rotation, const Vector2Df& scale) const;
		Matrix2D createTransform(const Vector2Df& position, float rotation, const Vector2Df& scale) const;

	public:
		TransformComponent(GameObject* ptrGameObject);

		void moveBy(const Vector2Df& offset);
		void moveBy(float offsetX, float offsetY);
		void setWorldPosition(const Vector2Df& position);
		void setWorldPosition(float positionX, float positionY);
		void setLocalPosition(const Vector2Df& position);
		void setLocalPosition(float positionX, float positionY);

		void rotateBy(float offset);
		void setWorldRotation(float angle);
		void setLocalRotation(float angle);

		void scaleBy(const Vector2Df& scale);
		void scaleBy(float scaleX, float scaleY);
		void setWorldScale(const Vector2Df& scale);
		void setWorldScale(float scaleX, float scaleY);
		void setLocalScale(const Vector2Df& scale);
		void setLocalScale(float scaleX, float scaleY);

		const Vector2Df& getWorldPosition() const;
		const Vector2Df& getLocalPosition() const;

		const float getWorldRotation() const;
		const float getLocalRotation() const;

		const Vector2Df& getWorldScale() const;
		const Vector2Df& getLocalScale() const;

		void setParent(TransformComponent* ptrParent);
		TransformComponent* getParent() const;

		const Matrix2D getWorldTransform() const;
		void print() const;

		void update(float deltaTime) override;
		void render() override;
	};
}