#include "Player.h"

#include <ResourceSystem.h>

namespace RoguelikeGame
{
	Player::Player()
	{
		ptrGameObject = CustomEngine::GameWorld::getInstance()->createGameObject();
		auto playerRenderer = ptrGameObject->addComponent<CustomEngine::SpriteRendererComponent>();

		playerRenderer->setTexture(*CustomEngine::ResourceSystem::getInstance()->getTextureShared("ball"));
		playerRenderer->setPixelSize(32, 32);

		auto playerCamera = ptrGameObject->addComponent<CustomEngine::CameraComponent>();
		playerCamera->setWindow(&CustomEngine::RenderSystem::getInstance()->getMainWindow());
		playerCamera->setBaseResolution(1280, 720);

		auto playerInput = ptrGameObject->addComponent<CustomEngine::InputComponent>();
	}

	CustomEngine::GameObject* Player::getGameObject()
	{
		return ptrGameObject;
	}
}