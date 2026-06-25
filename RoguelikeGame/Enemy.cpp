#include "Enemy.h"

#include "ResourceSystem.h"
#include "FollowComponent.h"
#include "MovementComponent.h"
#include "SpriteColliderComponent.h"
#include "SpriteDirectionComponent.h"

namespace RoguelikeGame
{
	Enemy::Enemy(const CustomEngine::Vector2Df& position)
	{
		gameObject = CustomEngine::GameWorld::getInstance()->createGameObject("Nito");
		auto transform = gameObject->getComponent<CustomEngine::TransformComponent>();
		transform->setWorldPosition(position);

		auto renderer = gameObject->addComponent<CustomEngine::SpriteRendererComponent>();
		renderer->setTexture(*CustomEngine::ResourceSystem::getInstance()->getTextureShared("txtr_enemy"));
		renderer->setPixelSize(128, 128);

		auto follower = gameObject->addComponent<CustomEngine::FollowComponent>();
		follower->setHeroAsTarget();
		follower->setSpeed(100.f);

		auto rigidbody = gameObject->addComponent<CustomEngine::RigidbodyComponent>();
		rigidbody->setKinematic(false);

		auto collider = gameObject->addComponent<CustomEngine::SpriteColliderComponent>();
	}

	CustomEngine::GameObject* Enemy::getGameObject()
	{
		return gameObject;
	}
}
