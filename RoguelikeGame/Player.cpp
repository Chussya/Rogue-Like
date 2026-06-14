#include "Player.h"

#include <ResourceSystem.h>
#include <MovementComponent.h>
#include <SpriteColliderComponent.h>
#include <SpriteDirectionComponent.h>

namespace RoguelikeGame
{
	Player::Player(const CustomEngine::Vector2Df& position)
	{
		ptrGameObject = CustomEngine::GameWorld::getInstance()->createGameObject("Hero");

		auto transform = ptrGameObject->getComponent<CustomEngine::TransformComponent>();
		transform->setWorldPosition(position);

		auto renderer = ptrGameObject->addComponent<CustomEngine::SpriteRendererComponent>();
		renderer->setTexture(*CustomEngine::ResourceSystem::getInstance()->getTextureShared("txtr_player"));
		renderer->setPixelSize(128, 128);

		auto camera = ptrGameObject->addComponent<CustomEngine::CameraComponent>();
		camera->setWindow(&CustomEngine::RenderSystem::getInstance()->getMainWindow());
		camera->setBaseResolution(1280, 720);

		auto input = ptrGameObject->addComponent<CustomEngine::InputComponent>();

		auto movement = ptrGameObject->addComponent<CustomEngine::MovementComponent>();
		movement->setSpeed(400.f);

		auto spriteDirection = ptrGameObject->addComponent<CustomEngine::SpriteDirectionComponent>();

		auto rigidbody = ptrGameObject->addComponent<CustomEngine::RigidbodyComponent>();
		rigidbody->setKinematic(false);

		auto collider = ptrGameObject->addComponent<CustomEngine::SpriteColliderComponent>();
	}

	CustomEngine::GameObject* Player::getGameObject()
	{
		return ptrGameObject;
	}
}