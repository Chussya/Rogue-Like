#include <SFML/Graphics.hpp>
#include "Application.h"
#include "Engine.h"

using namespace RoguelikeGame;

int main()
{
	Engine engine;
	engine.init();
	engine.run();

	Application::getInstance().run();

	return 0;
}
