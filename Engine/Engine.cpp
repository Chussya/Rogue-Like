#include "pch.h"
#include "Engine.h"
#include <iostream>

Engine::Engine(){}

void Engine::init()
{
	std::cout << "Engine initialized" << std::endl;
}

void Engine::run()
{
	std::cout << "Engine started" << std::endl;
}