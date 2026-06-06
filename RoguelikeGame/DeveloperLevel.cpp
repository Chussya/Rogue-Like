#include "DeveloperLevel.h"

using namespace CustomEngine;

namespace RoguelikeGame
{
	void DeveloperLevel::start()
	{
		player = std::make_shared<Player>();
	}
	void DeveloperLevel::restart()
	{
		stop();
		start();
	}
	void DeveloperLevel::stop()
	{
		GameWorld::getInstance()->clear();
	}
}