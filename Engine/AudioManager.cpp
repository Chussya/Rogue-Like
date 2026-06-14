#include "pch.h"

#include "AudioManager.h"

#include <assert.h>

namespace CustomEngine
{
	void AudioManager::loadMusic(const std::string path)
	{
		assert(music.openFromFile(path));

		music.setLoop(true);
	}

	void AudioManager::loadSoundBuffer(const ESoundEffect eSoundEffect, const std::string& path)
	{
		if (!path.empty())
		{
			sf::SoundBuffer soundBuf;
			assert(soundBuf.loadFromFile(path));
			tracks.insert({ eSoundEffect, soundBuf });
		}
	}

	sf::SoundBuffer& AudioManager::getSoundBuffer(const ESoundEffect eSoundEffect)
	{
		return tracks[eSoundEffect];
	}

	bool AudioManager::isMusicPlaying()
	{
		return music.getStatus() == sf::Music::Playing;
	}

	void AudioManager::setMusicVolume(const float volume)
	{
		music.setVolume(volume);
	}

	void AudioManager::playFullSound(const ESoundEffect eSoundEffect)
	{
		sf::Sound sound{ tracks[eSoundEffect] };

		//sound.setVolume(GAME_SETTINGS.getSoundVolume());
		sound.play();

		while (sound.getStatus() == sf::Sound::Playing)
		{
			// wait end of sound...
		}
	}

	void AudioManager::playMusic()
	{
		music.play();
	}

	void AudioManager::stopMusic()
	{
		music.stop();
	}
}
