#pragma once

#include "SFML/Graphics.hpp"

namespace CustomEngine
{
	class Engine
	{
	private:
		Engine();
		~Engine() = default;

	public:
		Engine(const Engine& app) = delete;
		Engine& operator= (const Engine&) = delete;

		static Engine* getInstance();

		void run();
	};
}