#include "pch.h"

#include "GameObject.h"

namespace CustomEngine
{
	// Private

	void GameObject::addChild(GameObject* child)
	{
		children.push_back(child);
	}

	void GameObject::removeChild(GameObject* child)
	{
		children.erase(std::remove_if(children.begin(), children.end(), [child](GameObject* obj) { return obj == child; }), children.end());
	}

	// Public

	GameObject::GameObject()
	{
		addComponent<TransformComponent>();
	}

	GameObject::GameObject(std::string name)
	{
		this->name = name;
		addComponent<TransformComponent>();
	}

	GameObject::~GameObject()
	{
		for (auto component : components)
		{
			delete component;
		}
		components.clear();
		children.clear();
	}

	std::string GameObject::getName() const
	{
		return name;
	}

	void GameObject::print(int depth) const
	{
		std::cout << std::string(depth * 2, ' ') << getName() << std::endl;
		for (auto& component : components)
		{
			std::cout << std::string(depth * 2, ' ') << "::" << component << std::endl;
		}

		for (GameObject* child : children)
		{
			child->print(depth + 1);
		}
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