#pragma once

namespace CustomEngine
{
	class Scene
	{
	public:
		virtual void start() = 0;
		virtual void restart() = 0;
		virtual void stop() = 0;
	};
}