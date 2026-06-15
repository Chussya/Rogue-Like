#pragma once

#include "Vector2D.h"

namespace CustomEngine
{
	class Settings
	{
	public:
		const Vector2Df CAMERA_RESOLUTION = {800, 600};

		// Single instance of game settings
		static Settings& getInstance()
		{
			static Settings settings;
			return settings;
		}
	};
}
#define SETTINGS Settings::getInstance()