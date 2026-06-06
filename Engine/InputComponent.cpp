#include "pch.h"

#include "InputComponent.h"

namespace CustomEngine
{
	InputComponent::InputComponent(GameObject* ptrGameObject) : Component(ptrGameObject) {}

	float InputComponent::getHorizontalAxis() const
	{
		return horizontalAxis;
	}

	float InputComponent::getVerticalAxis() const
	{
		return verticalAxis;
	}

	void InputComponent::update(float deltaTime)
	{
		verticalAxis = 0.f;
		horizontalAxis = 0.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			verticalAxis += 1.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			verticalAxis -= 1.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			horizontalAxis += 1.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			horizontalAxis -= 1.f;
		}
	}

	void InputComponent::render(){}
}
