#pragma once

#include <iostream>

#include "TransformComponent.h"

namespace CustomEngine
{
	class TransformComponent;

	class GameObject
	{
	private:
		std::vector<Component*> components{};

	public:
		GameObject();
		~GameObject();

		template<typename C>
		C* addComponent()
		{
			if constexpr (!std::is_base_of<Component, C>::value)
			{
				std::cout << "Component's type must be derived from Component." << std::endl;
				return nullptr;
			}
			if constexpr (std::is_same<C, TransformComponent>::value)
			{
				if (getComponent<TransformComponent>() != nullptr)
				{
					std::cout << "Can't add Transform because it will break the engine loop." << std::endl;
					return nullptr;
				}
			}

			C* component = new C(this);

			components.push_back(component);

			std::cout << "Add new component: " << component << std::endl;
			
			return component;
		}

		void removeComponent(Component* component)
		{
			components.erase(std::remove_if(components.begin(), components.end(),
				[component](Component* obj)
				{
					return obj == component;
				}), components.end());
			delete component;

			std::cout << "Components have been deleted.";
		}

		template<typename C>
		C* getComponent() const
		{
			for (const auto& component : components)
			{
				if (auto casted = dynamic_cast<C*>(component))
				{
					return casted;
				}
			}
			return nullptr;
		}

		void update(float deltaTime);
		void render();
	};
}