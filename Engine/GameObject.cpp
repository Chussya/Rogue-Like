#include "pch.h"

#include "GameObject.h"

namespace CustomEngine
{
	GameObject::GameObject()
	{
		addComponent<TransformComponent>();
	}

	GameObject::~GameObject()
	{
		for (auto component : components)
		{
			delete component;
		}
		components.clear();
	}

	void GameObject::update(float deltaTime)
	{
		for (auto& component : components)
		{
			component->update(deltaTime);
		}
	}

	void GameObject::render()
	{
		for (auto& component : components)
		{
			component->render();
		}
	}
}