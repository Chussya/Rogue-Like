#pragma once

#include <iostream>
#include <array>

#include "Scene.h"
#include "Player.h"

using namespace CustomEngine;

namespace RoguelikeGame
{
	class DeveloperLevel : public Scene
	{
	private:
		std::shared_ptr<Player> player;

	public:
		void start() override;
		void restart() override;
		void stop() override;
	};
}