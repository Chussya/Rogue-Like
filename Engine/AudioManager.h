#pragma once

#include <unordered_map>
#include <SFML/Audio.hpp>

namespace CustomEngine
{
	class AudioManager
	{
	public:
		enum class ESoundEffect
		{
			Death = 1,
			Hit,
			Effect,
			Fail,
			Victory,
		};

	private:
		std::unordered_map<ESoundEffect, sf::SoundBuffer> sounds;
		sf::Music music;

	public:
		__declspec(dllexport) void loadMusic(const std::string path);
		__declspec(dllexport) void loadSoundBuffer(const ESoundEffect eSoundEffect, const std::string& path);

		__declspec(dllexport) sf::SoundBuffer& getSoundBuffer(const ESoundEffect eSoundEffect);

		__declspec(dllexport) bool isMusicPlaying();

		__declspec(dllexport) void setMusicVolume(const float volume);

		__declspec(dllexport) void playFullSound(const ESoundEffect eSoundEffect);
		__declspec(dllexport) void playMusic();
		__declspec(dllexport) void stopMusic();
	};
}