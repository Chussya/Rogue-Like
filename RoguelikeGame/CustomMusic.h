#pragma once

#include <GameObject.h>
#include <GameWorld.h>
#include <AudioComponent.h>
#include <ResourceSystem.h>

namespace RoguelikeGame
{
	class CustomMusic
	{
	private:
		CustomEngine::GameObject* gameObject;

	public:
		CustomMusic(const std::string& musicName);
	};
}

