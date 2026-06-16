#include "EnemySpawner.h"

#include "CustomMath.h"

namespace RoguelikeGame
{
    void EnemySpawner::spawn(DeveloperLevel* level, CustomEngine::GameObject* player)
    {
        if (level->getFloors().empty())
            return;

        const int floorIndex{ Math::getRandNumTo((int)level->getFloors().size()) };
        const auto& floor{ level->getFloors()[floorIndex] };

        CustomEngine::Vector2Df spawnPos{ floor->getGameObject()->getComponent<CustomEngine::TransformComponent>()->getWorldPosition() };

        std::make_unique<Enemy>(spawnPos, player);
    }
}