#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "TransformComponent.h"

namespace CustomEngine
{
    class CameraComponent : public Component
    {
    private:
        TransformComponent* transform;
        sf::RenderWindow* window;
        sf::View* view;

    public:
        CameraComponent(GameObject* ptrGameObject);
        ~CameraComponent();

        void setWindow(sf::RenderWindow* window);
        void zoomBy(const float zoom);

        void setBaseResolution(const int width, const int height);

        void update(float deltaTime) override;
        void render() override;
    };
}

