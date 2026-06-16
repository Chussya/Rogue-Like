#pragma once

#include "DeveloperLevel.h"

namespace RoguelikeGame
{
    class LevelManager
    {
    private:
        std::unique_ptr<DeveloperLevel> level;

        LevelManager(LevelManager const&) = delete;
        LevelManager& operator=(LevelManager const&) = delete;

        LevelManager(){}
        ~LevelManager(){}

    public:
        static LevelManager* getInstance();
        void loadLevel();
    };
}