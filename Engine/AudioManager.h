#pragma once

// This block necessary for export to another projects
#ifdef ENGINE_EXPORTS
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif // ENGINE_EXPORTS

#include <unordered_map>
#include <SFML/Audio.hpp>

namespace CustomEngine
{
	class ENGINE_API AudioManager
	{
	public:
		enum class ENGINE_API ESoundEffect
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
		void loadMusic(const std::string path);
		void loadSoundBuffer(const ESoundEffect eSoundEffect, const std::string& path);

		sf::SoundBuffer& getSoundBuffer(const ESoundEffect eSoundEffect);

		bool isMusicPlaying();

		void setMusicVolume(const float volume);

		void playFullSound(const ESoundEffect eSoundEffect);
		void playMusic();
		void stopMusic();
	};
}