#pragma once

#include <memory>

namespace CustomEngine
{
	class Collidable
	{
	public:
		enum class ECollisionShape
		{
			Rectangle = 1,
			Circle,

			Empty = 0
		};

		enum class ECollisionSide
		{
			Right = 1,
			Left,
			Top,
			Bottom,
			Angle,

			Empty = 0
		};

	private:
		ECollisionShape shape;
		ECollisionSide collision;

	protected:
		virtual ECollisionShape getShape() { return shape; }
		virtual ECollisionSide getCollisionSide() { return collision; }

		virtual void onHit() { collision = ECollisionSide::Empty; };

	public:
		__declspec(dllexport) Collidable(ECollisionShape shape) : shape{ shape }, collision { ECollisionSide::Empty } {}
		__declspec(dllexport) virtual ~Collidable() = default;

		// Setters

		__declspec(dllexport) virtual void setCollisionSide(ECollisionSide collision) { this->collision = collision; }

		// No signature methods:

		__declspec(dllexport) virtual bool isCollide(std::shared_ptr<Collidable> collidable) = 0;

		// Signatures methods

		__declspec(dllexport) virtual bool checkCollision(std::shared_ptr<Collidable> collidable)
		{
			if (isCollide(collidable))
			{
				onHit();
				collidable->onHit();
				return true;
			}
			return false;
		}
	};
}