#pragma once

#include "DeveloperLevel.h"

namespace RoguelikeGame
{
	class EnemySpawner
	{
	public:
		void spawn(DeveloperLevel* level, CustomEngine::GameObject* player);
	};
}

