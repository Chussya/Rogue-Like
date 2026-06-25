#include "pch.h"

#include "AudioComponent.h"

namespace CustomEngine
{
	AudioComponent::AudioComponent(GameObject* gameObject) : Component(gameObject)
	{
		sound = new sf::Sound();
	}

	AudioComponent::~AudioComponent()
	{
		sound->stop();
		delete sound;
	}

	void AudioComponent::setAudio(const sf::SoundBuffer& sound)
	{
		this->sound->setBuffer(sound);
	}

	void AudioComponent::setLoop(bool loop)
	{
		sound->setLoop(loop);
	}

	void AudioComponent::setVolume(float volume)
	{
		sound->setVolume(volume);
	}

	void AudioComponent::play()
	{
		if (sound->getStatus() != sf::SoundSource::Playing)
		{
			sound->play();
		}
	}

	void AudioComponent::stop()
	{
		sound->stop();
	}

	void AudioComponent::pause()
	{
		sound->pause();
	}

	void AudioComponent::resume()
	{
		if (sound->getStatus() != sf::SoundSource::Playing)
		{
			sound->play();
		}
	}

	void AudioComponent::update(float deltaTime) {}

	void AudioComponent::render() {}
}
