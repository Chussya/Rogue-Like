#include "pch.h"

#include "PhysicsSystem.h"

namespace CustomEngine
{
	PhysicsSystem* PhysicsSystem::getInstance()
	{
		static PhysicsSystem physicsSystem;
		return &physicsSystem;
	}

	float PhysicsSystem::getFixedDeltaTime() const
	{
		return fixedDeltaTime;
	}

	void PhysicsSystem::subscribe(ColliderComponent* collider)
	{
		std::cout << "Subscribe " << collider << std::endl;
		colliders.push_back(collider);
	}

	void PhysicsSystem::unsubscribe(ColliderComponent* collider)
	{
		std::cout << "Unsubscribe " << collider << std::endl;

		colliders.erase(std::remove_if(colliders.begin(), colliders.end(), [collider](ColliderComponent* obj) { return obj == collider; }), colliders.end());
	}

	void PhysicsSystem::update()
	{
		for (int i = 0; i < colliders.size(); i++)
		{
			auto body = colliders[i]->getGameObject()->getComponent<RigidbodyComponent>();
			if (body->getKinematic())
			{
				continue;
			}

			for (int j = 0; j < colliders.size(); j++)
			{
				if (j == i)
				{
					continue;
				}

				sf::FloatRect intersection;
				if (colliders[i]->bounds.intersects(colliders[j]->bounds, intersection))
				{
					if (colliders[i]->isTrigger != colliders[j]->isTrigger)
					{
						if (triggersEnteredPair.find(colliders[i]) == triggersEnteredPair.end() && triggersEnteredPair.find(colliders[j]) == triggersEnteredPair.end())
						{
							auto trigger = new Trigger(colliders[i], colliders[j]);
							colliders[i]->onTriggerEnter(*trigger);
							colliders[j]->onTriggerEnter(*trigger);

							triggersEnteredPair.emplace(colliders[i], colliders[j]);
						}
					} else if (!colliders[i]->isTrigger)
					{
						float intersectionWidth = intersection.width;
						float intersectionHeight = intersection.height;
						Vector2Df intersectionPosition = { intersection.left - 0.5f * intersectionWidth, intersection.top - 0.5f * intersectionHeight };

						Vector2Df aPosition = { colliders[i]->bounds.left,  colliders[i]->bounds.top };
						auto aTransform = colliders[i]->getGameObject()->getComponent<TransformComponent>();

						if (intersectionWidth > intersectionHeight)
						{
							if (intersectionPosition.y > aPosition.y)
							{
								aTransform->moveBy({ 0, -intersectionHeight });
								std::cout << "Top collision" << std::endl;
							} else
							{
								aTransform->moveBy({ 0, intersectionHeight });
								std::cout << "Down collision" << std::endl;
							}
						} else
						{
							if (intersectionPosition.x > aPosition.x)
							{
								aTransform->moveBy({ -intersectionWidth, 0.f });
								std::cout << "Right collision" << std::endl;
							} else
							{
								aTransform->moveBy({ intersectionWidth, 0.f });
								std::cout << "Left collision" << std::endl;
							}
						}

						auto collision = new Collision(colliders[i], colliders[j], intersection);
						colliders[i]->onCollision(*collision);
						colliders[j]->onCollision(*collision);
					}
				}
			}
		}

		for (auto triggeredPair = triggersEnteredPair.cbegin(), nextTriggeredPair = triggeredPair; triggeredPair != triggersEnteredPair.cend(); triggeredPair = nextTriggeredPair)
		{
			++nextTriggeredPair;
			if (!triggeredPair->first->bounds.intersects(triggeredPair->second->bounds))
			{
				auto trigger = new Trigger(triggeredPair->first, triggeredPair->second);
				triggeredPair->first->onTriggerExit(*trigger);
				triggeredPair->second->onTriggerExit(*trigger);

				triggersEnteredPair.erase(triggeredPair);
			}
		}
	}
}