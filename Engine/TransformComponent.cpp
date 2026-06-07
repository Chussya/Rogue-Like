#include "pch.h"
#include "TransformComponent.h"
#include <cmath>
#include <iostream>

namespace CustomEngine
{
	TransformComponent::TransformComponent(GameObject* ptrGameObject) : Component(ptrGameObject) {}

	void TransformComponent::moveBy(const Vector2Df& offset)
	{
		moveBy(offset.x, offset.y);
		isUpdated = false;
	}

	void TransformComponent::moveBy(float offsetX, float offsetY)
	{
		localPos.x += offsetX;
		localPos.y += offsetY;
		isUpdated = false;
	}

	void TransformComponent::setWorldPosition(const Vector2Df& pos)
	{
		setWorldPosition(pos.x, pos.y);
		isUpdated = false;
	}

	void TransformComponent::setWorldPosition(float posX, float posY)
	{
		Vector2Df newpos = { posX, posY };
		if (ptrParent == nullptr)
		{
			localPos = newpos;
		} else
		{
			Matrix2D newWorldTransform = createTransform(newpos, getWorldRotation(), getWorldScale());
			localTransform = ptrParent->getWorldTransform().getInversed() * newWorldTransform;

			setLocalInfoFrom(localTransform);

			isUpdated = false;
			updateLocalTransform();
		}
	}

	void TransformComponent::setLocalPosition(const Vector2Df& pos)
	{
		setLocalPosition(pos.x, pos.y);
		isUpdated = false;
	}

	void TransformComponent::setLocalPosition(float posX, float posY)
	{
		localPos.x = posX;
		localPos.y = posY;
		isUpdated = false;
	}

	void TransformComponent::rotateBy(float offset)
	{
		localRot = localRot + offset;
		while (localRot >= 360)
		{
			localRot -= 360;
		}
		while (localRot < 0)
		{
			localRot += 360;
		}
		isUpdated = false;
	}

	void TransformComponent::setWorldRotation(float angle)
	{
		if (ptrParent == nullptr)
		{
			localRot = angle;
		} else
		{
			Matrix2D newWorldTransform = createTransform(getWorldPosition(), angle, getWorldScale());
			localTransform = ptrParent->getWorldTransform().getInversed() * newWorldTransform;

			setLocalInfoFrom(localTransform);

			isUpdated = false;
			updateLocalTransform();
		}
	}

	void TransformComponent::setLocalRotation(float angle)
	{
		localRot = angle;
		while (localRot >= 360)
		{
			localRot -= 360;
		}
		while (localRot < 0)
		{
			localRot += 360;
		}
		isUpdated = false;
	}

	void TransformComponent::scaleBy(const Vector2Df& scale)
	{
		scaleBy(scale.x, scale.y);
		isUpdated = false;
	}

	void TransformComponent::scaleBy(float scaleX, float scaleY)
	{
		localScale.x *= scaleX;
		localScale.y *= scaleY;
		isUpdated = false;
	}

	void TransformComponent::setWorldScale(const Vector2Df& scale)
	{
		setWorldScale(scale.x, scale.y);
		isUpdated = false;
	}

	void TransformComponent::setWorldScale(float scaleX, float scaleY)
	{
		Vector2Df newScale = { scaleX, scaleY };
		if (ptrParent == nullptr)
		{
			localScale = newScale;
		} else
		{
			Matrix2D newWorldTransform = createTransform(getWorldPosition(), getWorldRotation(), newScale);
			localTransform = ptrParent->getWorldTransform().getInversed() * newWorldTransform;

			setLocalInfoFrom(localTransform);

			isUpdated = false;
			updateLocalTransform();
		}
	}

	void TransformComponent::setLocalScale(const Vector2Df& scale)
	{
		setLocalScale(scale.x, scale.y);
		isUpdated = false;
	}

	void TransformComponent::setLocalScale(float scaleX, float scaleY)
	{
		localScale.x = scaleX;
		localScale.y = scaleY;
		isUpdated = false;
	}

	const Vector2Df& TransformComponent::getWorldPosition() const
	{
		updateLocalTransform();
		if (ptrParent == nullptr)
		{
			return getLocalPosition();
		}

		setWorldInfoFrom(ptrParent->getWorldTransform() * localTransform);
		return pos;
	}

	const Vector2Df& TransformComponent::getLocalPosition() const
	{
		updateLocalTransform();
		return localPos;
	}

	const float TransformComponent::getWorldRotation() const
	{
		updateLocalTransform();
		if (ptrParent == nullptr)
		{
			return getLocalRotation();
		}

		setWorldInfoFrom(ptrParent->getWorldTransform() * localTransform);
		return rot;
	}

	const float TransformComponent::getLocalRotation() const
	{
		updateLocalTransform();
		return localRot;
	}

	const Vector2Df& TransformComponent::getWorldScale() const
	{
		updateLocalTransform();
		if (ptrParent == nullptr)
		{
			return getLocalScale();
		}

		setWorldInfoFrom(ptrParent->getWorldTransform() * localTransform);
		return scale;
	}

	const Vector2Df& TransformComponent::getLocalScale() const
	{
		updateLocalTransform();
		return localScale;
	}

	void TransformComponent::setParent(TransformComponent* ptrParent)
	{
		if (this->ptrParent == nullptr && ptrParent != nullptr)
		{
			ptrParent->ptrGameObject->addChild(ptrGameObject);
			localTransform = ptrParent->getWorldTransform().getInversed() * localTransform;
		} else if (this->ptrParent != nullptr && ptrParent == nullptr)
		{
			this->ptrParent->ptrGameObject->removeChild(ptrGameObject);
			localTransform = this->ptrParent->getWorldTransform() * localTransform;
		} else if (this->ptrParent != nullptr && ptrParent != nullptr)
		{
			this->ptrParent->ptrGameObject->removeChild(ptrGameObject);
			ptrParent->ptrGameObject->addChild(ptrGameObject);
			localTransform = ptrParent->getWorldTransform().getInversed() * (this->ptrParent->getWorldTransform() * localTransform);
		}

		setLocalInfoFrom(localTransform);

		this->ptrParent = ptrParent;
		isUpdated = false;
	}

	TransformComponent* TransformComponent::getParent() const
	{
		return ptrParent;
	}

	const Matrix2D TransformComponent::getWorldTransform() const
	{
		updateLocalTransform();

		if (ptrParent == nullptr)
		{
			return localTransform;
		}

		return ptrParent->getWorldTransform() * localTransform;
	}

	void TransformComponent::print() const
	{
		std::cout << "Transform name : " << ptrGameObject->getName() << std::endl;

		std::cout << "pos" << std::endl;
		std::cout << "  World: (" << getWorldPosition().x << ", " << getWorldPosition().y << ")" << std::endl;
		std::cout << "  Local: (" << getLocalPosition().x << ", " << getLocalPosition().y << ")" << std::endl;

		std::cout << "Rotation" << std::endl;
		std::cout << "  World: " << getWorldRotation() << std::endl;
		std::cout << "  Local: " << getLocalRotation() << std::endl;

		std::cout << "Scale" << std::endl;
		std::cout << "  World: (" << getWorldScale().x << ", " << getWorldScale().y << ")" << std::endl;
		std::cout << "  Local: (" << getLocalScale().x << ", " << getLocalScale().y << ")" << std::endl;
	}

	void TransformComponent::setWorldInfoFrom(const Matrix2D& transform) const
	{
		pos.x = transform.getMatrix()[0][2];
		pos.y = transform.getMatrix()[1][2];

		scale.x = std::sqrt(transform.getMatrix()[0][0] * transform.getMatrix()[0][0] + transform.getMatrix()[1][0] * transform.getMatrix()[1][0]);
		scale.y = std::sqrt(transform.getMatrix()[0][1] * transform.getMatrix()[0][1] + transform.getMatrix()[1][1] * transform.getMatrix()[1][1]);

		rot = std::atan2(transform.getMatrix()[0][1], transform.getMatrix()[0][0]) * 180 / 3.14159265;
	}

	void TransformComponent::setLocalInfoFrom(const Matrix2D& transform) const
	{
		localPos.x = transform.getMatrix()[0][2];
		localPos.y = transform.getMatrix()[1][2];

		localScale.x = std::sqrt(transform.getMatrix()[0][0] * transform.getMatrix()[0][0] + transform.getMatrix()[1][0] * transform.getMatrix()[1][0]);
		localScale.y = std::sqrt(transform.getMatrix()[0][1] * transform.getMatrix()[0][1] + transform.getMatrix()[1][1] * transform.getMatrix()[1][1]);

		localRot = std::atan2(transform.getMatrix()[0][1], transform.getMatrix()[0][0]) * 180 / 3.14159265;
	}

	void TransformComponent::updateLocalTransform() const
	{
		if (!isUpdated)
		{
			localTransform = createTransform(localPos, localRot, localScale);
			isUpdated = true;
		}
	}

	void TransformComponent::updateLocalTransform(const Vector2Df& pos, float rot, const Vector2Df& scale) const
	{
		if (!isUpdated)
		{
			localTransform = createTransform(pos, rot, scale);
			isUpdated = true;
		}
	}

	Matrix2D TransformComponent::createTransform(const Vector2Df& pos, float rot, const Vector2Df& scale) const
	{
		return Matrix2D(pos, rot, scale);
	}

	void TransformComponent::update(float deltaTime)
	{

	}

	void TransformComponent::render()
	{

	}
}