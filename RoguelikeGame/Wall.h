#pragma once

#include "GameObject.h"

namespace RoguelikeGame
{
	class Wall
	{
	private:
		CustomEngine::GameObject* ptrGameObject;

	public:
		Wall(const CustomEngine::Vector2Df& position);
	};
}