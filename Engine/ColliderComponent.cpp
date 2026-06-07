#include "pch.h"

#include "ColliderComponent.h"

namespace CustomEngine
{
	// Private

	void ColliderComponent::onCollision(Collision collision)
	{
		for (int i = 0; i < onCollisionActions.size(); i++)
		{
			onCollisionActions[i](collision);
		}
	}

	void ColliderComponent::onTriggerEnter(Trigger trigger)
	{
		for (int i = 0; i < onTriggerEnterActions.size(); i++)
		{
			onTriggerEnterActions[i](trigger);
		}
	}

	void ColliderComponent::onTriggerExit(Trigger trigger)
	{
		for (int i = 0; i < onTriggerExitActions.size(); i++)
		{
			onTriggerExitActions[i](trigger);
		}
	}

	// Public

	ColliderComponent::ColliderComponent(GameObject* gameObject) : Component(gameObject) {}

	void ColliderComponent::setTrigger(bool newIsTrigger)
	{
		isTrigger = newIsTrigger;
	}

	void ColliderComponent::subscribeCollision(std::function<void(Collision)> onCollisionAction)
	{
		onCollisionActions.push_back(onCollisionAction);
	}

	void ColliderComponent::unsubscribeCollision(std::function<void(Collision)> onCollisionAction)
	{
		onCollisionActions.erase(std::remove_if
		(
			onCollisionActions.begin(),
			onCollisionActions.end(),
			[&onCollisionAction](const std::function<void(Collision)>& action)
			{
				return action.target<void(Collision)>() == onCollisionAction.target<void(Collision)>();
			}
		), onCollisionActions.end());
	}

	void ColliderComponent::subscribeTriggerEnter(std::function<void(Trigger)> onTriggerEnterAction)
	{
		onTriggerEnterActions.push_back(onTriggerEnterAction);
	}

	void ColliderComponent::unsubscribeTriggerEnter(std::function<void(Trigger)> onTriggerEnterAction)
	{
		onTriggerEnterActions.erase(std::remove_if
		(
			onTriggerEnterActions.begin(),
			onTriggerEnterActions.end(),
			[&onTriggerEnterAction](const std::function<void(Trigger)>& action)
			{
				return action.target<void(Trigger)>() == onTriggerEnterAction.target<void(Trigger)>();
			}
		), onTriggerEnterActions.end());
	}

	void ColliderComponent::subscribeTriggerExit(std::function<void(Trigger)> onTriggerExitAction)
	{
		onTriggerExitActions.push_back(onTriggerExitAction);
	}

	void ColliderComponent::unsubscribeTriggerExit(std::function<void(Trigger)> onTriggerExitAction)
	{
		onTriggerExitActions.erase(std::remove_if
		(
			onTriggerExitActions.begin(),
			onTriggerExitActions.end(),
			[&onTriggerExitAction](const std::function<void(Trigger)>& action)
			{
				return action.target<void(Trigger)>() == onTriggerExitAction.target<void(Trigger)>();
			}
		), onTriggerExitActions.end());
	}
}