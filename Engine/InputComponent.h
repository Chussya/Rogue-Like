#pragma once

#include <SFML/Window.hpp>

#include "Component.h"

namespace CustomEngine
{
    class InputComponent : public Component
    {
    private:
        float horizontalAxis{ 0.f };
        float verticalAxis{ 0.f };

    public:
        InputComponent(GameObject* ptrGameObject);

        float getHorizontalAxis() const;
        float getVerticalAxis() const;

        void update(float deltaTime) override;
        void render() override;
    };
}

