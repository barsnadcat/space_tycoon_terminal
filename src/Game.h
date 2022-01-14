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
    void Reset(int n);
private:
    void RenderLand(Land&l, std::stringstream& res) const;
    void RenderPerson(Person* p, std::stringstream& res) const;

    UpdateContext mUpdateContext;
    std::unique_ptr<Settlement> mSettlement;
};
