#include "Wall.h"

#include "GameWorld.h"
#include "ResourceSystem.h"
#include "SpriteRendererComponent.h"
#include "SpriteColliderComponent.h"

namespace RoguelikeGame
{
	Wall::Wall(const CustomEngine::Vector2Df& position)
	{
		ptrGameObject = CustomEngine::GameWorld::getInstance()->createGameObject("Wall");
		auto transform = ptrGameObject->getComponent<CustomEngine::TransformComponent>();
		transform->setWorldPosition(position);

		auto renderer = ptrGameObject->addComponent<CustomEngine::SpriteRendererComponent>();
		renderer->setTexture(*CustomEngine::ResourceSystem::getInstance()->getTextureShared("txtr_wall"));
		renderer->setPixelSize(128, 128);

		auto rigidbody = ptrGameObject->addComponent<CustomEngine::RigidbodyComponent>();
		rigidbody->setKinematic(true);

		auto collider = ptrGameObject->addComponent<CustomEngine::SpriteColliderComponent>();
	}
}