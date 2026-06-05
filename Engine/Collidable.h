#pragma once

// This block necessary for export to another projects
#ifdef ENGINE_EXPORTS
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif // ENGINE_EXPORTS

#include <memory>

namespace CustomEngine
{
	class ENGINE_API Collidable
	{
	public:
		enum class ENGINE_API ECollisionShape
		{
			Rectangle = 1,
			Circle,

			Empty = 0
		};

		enum class ENGINE_API ECollisionSide
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
		Collidable(ECollisionShape shape) : shape{ shape }, collision { ECollisionSide::Empty } {}
		virtual ~Collidable() = default;

		// Setters

		virtual void setCollisionSide(ECollisionSide collision) { this->collision = collision; }

		// No signature methods:

		virtual bool isCollide(std::shared_ptr<Collidable> collidable) = 0;

		// Signatures methods

		virtual bool checkCollision(std::shared_ptr<Collidable> collidable)
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