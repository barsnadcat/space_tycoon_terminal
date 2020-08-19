#pragma once

#include <Space.h>
#include <UpdateContext.h>
#include <Person.h>

class Game
{
public:
    Game();
    void Run(int n);
    void Reset();
private:
    UpdateContext mUpdateContext;
    std::unique_ptr<Space> mSpace;
};