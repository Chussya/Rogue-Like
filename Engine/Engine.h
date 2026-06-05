#pragma once

// This block necessary for export to another projects
#ifdef ENGINE_EXPORTS
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif // ENGINE_EXPORTS

namespace CustomEngine
{
	class ENGINE_API Engine
	{
	public:
		Engine();

		void init();
		void run();
	};
}
