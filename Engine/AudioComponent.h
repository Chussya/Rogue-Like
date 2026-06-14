#pragma once

#include <SFML/Audio.hpp>

#include "Component.h"

namespace CustomEngine
{
	class AudioComponent : public Component
	{
	private:
		sf::Sound* sound;

	public:
		AudioComponent(GameObject* gameObject);
		~AudioComponent();

		void setAudio(const sf::SoundBuffer& audio);
		void setLoop(bool loop);

		void setVolume(float volume);
		void play();
		void stop();
		void pause();
		void resume();

		// Inherited via Component
		void update(float deltaTime) override;
		void render() override;
	};
}

