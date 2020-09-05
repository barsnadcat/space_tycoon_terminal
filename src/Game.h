#pragma once

#include <Settlement.h>
#include <UpdateContext.h>
#include <Person.h>

class Game
{
public:
    Game();
    void Run(int n);
    void Render() const;
    void Reset();
private:
    UpdateContext mUpdateContext;
    std::unique_ptr<Settlement> mSettlement;
};