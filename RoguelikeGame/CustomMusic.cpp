#include "CustomMusic.h"

namespace RoguelikeGame
{
	CustomMusic::CustomMusic(const std::string& soundName)
	{
		auto gameObject = CustomEngine::GameWorld::getInstance()->createGameObject("mus_" + soundName);

		auto music = gameObject->addComponent<CustomEngine::AudioComponent>();

		music->setAudio(*CustomEngine::ResourceSystem::getInstance()->getSound(soundName));
		music->setLoop(true);
		music->setVolume(25.f);
		music->play();
	}
}
