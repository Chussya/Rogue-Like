#pragma once

#include <iostream>

#include "TransformComponent.h"

namespace CustomEngine
{
	class TransformComponent;

	class GameObject
	{
	private:
		std::string name;

		std::vector<GameObject*> children = {};
		std::vector<Component*> components{};

		void addChild(GameObject* child);
		void removeChild(GameObject* child);

	public:
		GameObject();
		GameObject(std::string name);
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

		template <typename T>
		T* getComponentInChildren() const
		{
			T* component = getComponent<T>();
			if (component != nullptr || children.size() == 0)
			{
				return component;
			}

			for (const auto& child : children)
			{
				T* childComponent = child->getComponentInChildren<T>();
				if (childComponent != nullptr)
				{
					return childComponent;
				}
			}

			return nullptr;
		}

		template <typename T>
		std::vector<T*> getComponents() const
		{
			std::vector<T*> result;
			for (const auto& component : components)
			{
				if (auto casted = dynamic_cast<T*>(component))
				{
					result.push_back(casted);
				}
			}
			return result;
		}

		template <typename T>
		std::vector<T*> getComponentsInChildren() const
		{
			std::vector<T*> result;
			for (const auto& component : getComponents<T>())
			{
				result.push_back(component);
			}

			for (const auto& child : children)
			{
				for (const auto& childComponent : child->getComponentsInChildren<T>())
				{
					result.push_back(childComponent);
				}
			}

			return result;
		}

		std::string getName() const;
		void print(int depth = 0) const;

		void update(float deltaTime);
		void render();

		friend class GameWorld;
		friend class TransformComponent;
	};
}