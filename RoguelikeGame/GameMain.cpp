#include <SFML/Graphics.hpp>
#include "Application.h"
#include "Engine.h"

// For engine test
//#include <iostream>
//#include "windows.h"

using namespace RoguelikeGame;

int main()
{
	// For engine test
	//if (AllocConsole())
	//{
	//	FILE* fp;
	//	freopen_s(&fp, "CONOUT$", "w", stdout);
	//	freopen_s(&fp, "CONOUT$", "w", stderr);
	//} else
	//{
	//	std::cerr << "Console error..." << std::endl;
	//}

	Engine engine;
	engine.init();
	engine.run();

	Application::getInstance().run();

	return 0;
}
