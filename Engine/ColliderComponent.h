#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include "Component.h"
#include "Collision.h"
#include "Trigger.h"
#include "PhysicsSystem.h"

namespace CustomEngine
{
	class ColliderComponent : public Component
	{
	protected:
		sf::FloatRect bounds;
		bool isTrigger = false;

		void onCollision(Collision collision);
		void onTriggerEnter(Trigger trigger);
		void onTriggerExit(Trigger trigger);

		std::vector<std::function<void(Collision)>> onCollisionActions;
		std::vector<std::function<void(Trigger)>> onTriggerEnterActions;
		std::vector<std::function<void(Trigger)>> onTriggerExitActions;

	public:
		ColliderComponent(GameObject* gameObject);

		virtual void update(float deltaTime) = 0;
		virtual void render() = 0;

		void setTrigger(bool newIsTrigger);

		void subscribeCollision(std::function<void(Collision)> onCollisionAction);
		void unsubscribeCollision(std::function<void(Collision)> onCollisionAction);

		void subscribeTriggerEnter(std::function<void(Trigger)> onTriggerEnterAction);
		void unsubscribeTriggerEnter(std::function<void(Trigger)> onTriggerEnterAction);

		void subscribeTriggerExit(std::function<void(Trigger)> onTriggerExitAction);
		void unsubscribeTriggerExit(std::function<void(Trigger)> onTriggerExitAction);

		friend class PhysicsSystem;
	};
}