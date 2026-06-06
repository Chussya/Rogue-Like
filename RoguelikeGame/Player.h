#pragma once

#include "CameraComponent.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "InputComponent.h"
#include "GameObject.h"

namespace RoguelikeGame
{
	class Player
	{
	private:
		CustomEngine::GameObject* ptrGameObject;

	public:
		Player();
		CustomEngine::GameObject* getGameObject();
	};
}