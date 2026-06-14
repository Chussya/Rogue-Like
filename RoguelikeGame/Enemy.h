#pragma once

#include "Vector2D.h"
#include "GameWorld.h"
#include "GameObject.h"
#include "RenderSystem.h"
#include "InputComponent.h"
#include "CameraComponent.h"
#include "SpriteRendererComponent.h"

namespace RoguelikeGame
{
	class Enemy
	{
	private:
		CustomEngine::GameObject* gameObject;

	public:
		Enemy(const CustomEngine::Vector2Df& position, CustomEngine::GameObject* target);

		CustomEngine::GameObject* getGameObject();
	};
}

