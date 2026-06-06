#include "pch.h"
#include "CameraComponent.h"
#include "TransformComponent.h"

namespace CustomEngine
{
	CameraComponent::CameraComponent(GameObject* gameObject) : Component(gameObject)
	{
		view = new sf::View(sf::FloatRect(0, 0, 800, -600));
		transform = gameObject->getComponent<TransformComponent>();
	}

	CameraComponent::~CameraComponent()
	{
		delete view;
	}

	void CameraComponent::setBaseResolution(int width, int height)
	{
		view->reset(sf::FloatRect(0, 0, static_cast<float>(width), static_cast<float>(-height)));
	}

	void CameraComponent::setWindow(sf::RenderWindow* newWindow)
	{
		window = newWindow;
	}

	void CameraComponent::zoomBy(float newZoom)
	{
		if (newZoom <= 0)
		{
			std::cout << "Not allowed zoom lesser or equal than zero." << std::endl;
			return;
		}
		view->zoom(newZoom);
	}

	void CameraComponent::update(float deltaTime)
	{
		auto position = transform->getWorldPosition();
		auto rotation = transform->getWorldRotation();

		view->setCenter(convert<sf::Vector2f, Vector2Df>(position));
		view->setRotation(rotation);

		window->setView(*view);
	}

	void CameraComponent::render()
	{
		if (window == nullptr)
		{
			std::cout << "NULL window render." << std::endl;
		}
	}
}