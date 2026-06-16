#pragma once

#include "GameObject.h"

namespace RoguelikeGame
{
	class Floor
	{
	private:
		CustomEngine::GameObject* ptrGameObject;

	public:
		Floor(const CustomEngine::Vector2Df& position);

		CustomEngine::GameObject* getGameObject();
	};
}