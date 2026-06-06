#include "pch.h"

#include <iostream>

#include "Component.h"

namespace CustomEngine
{
	Component::Component(GameObject* ptrGameObject) : ptrGameObject(ptrGameObject) {}

	Component::~Component()
	{
		std::cout << "Delete component: " << this << std::endl;
	}

	GameObject* Component::getGameObject()
	{
		return ptrGameObject;
	}
}