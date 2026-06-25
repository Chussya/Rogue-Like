#include "Floor.h"

#include "GameWorld.h"
#include "ResourceSystem.h"
#include "SpriteRendererComponent.h"

namespace RoguelikeGame
{
	Floor::Floor(const CustomEngine::Vector2Df& position)
	{
		ptrGameObject = CustomEngine::GameWorld::getInstance()->createGameObject("Floor");
		auto transform = ptrGameObject->getComponent<CustomEngine::TransformComponent>();
		transform->setWorldPosition(position);

		auto renderer = ptrGameObject->addComponent<CustomEngine::SpriteRendererComponent>();
		renderer->setTexture(*CustomEngine::ResourceSystem::getInstance()->getTextureShared("txtr_floor"));
		renderer->setPixelSize(128, 128);
	}

	CustomEngine::GameObject* Floor::getGameObject()
	{
		return ptrGameObject;
	}
}