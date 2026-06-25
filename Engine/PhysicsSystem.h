#pragma once

#include <map>
#include <iostream>

#include "ColliderComponent.h"
#include "RigidbodyComponent.h"
#include "Vector2D.h"

namespace CustomEngine
{
	class PhysicsSystem
	{
	private:
		float fixedDeltaTime{ 0.02f };
		std::vector<ColliderComponent*> colliders;
		std::map<ColliderComponent*, ColliderComponent*> triggersEnteredPair;

		PhysicsSystem(){}
		~PhysicsSystem(){}

		PhysicsSystem(PhysicsSystem const&) = delete;
		PhysicsSystem& operator= (PhysicsSystem const&) = delete;

	public:
		static PhysicsSystem* getInstance();

		float getFixedDeltaTime() const;
		void subscribe(ColliderComponent* collider);
		void unsubscribe(ColliderComponent* collider);

		void update();
	};
}