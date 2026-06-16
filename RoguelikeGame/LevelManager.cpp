#include "LevelManager.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "pch.h"
#include "Enemy.h"

namespace RoguelikeGame
{

    LevelManager* LevelManager::getInstance()
    {
        static LevelManager levels;
        return &levels;
    }

    void LevelManager::loadLevel()
    {
        if (level == nullptr)
        {
            level = std::make_unique<DeveloperLevel>();
        }
        level->start();

        // seed for random positions
        std::srand((int)std::time(nullptr));

        level->createSpawner();
    }

}