#include <Game.h>
#include <easylogging++.h>

Game::Game()
{
    mSpace.reset(new Space());    
}

void Game::Run(int n)
{    
    for (int i = 0; i < n; i++)
    {
        mSpace->Update(mUpdateContext);
        LOG(INFO) << "Updated";
    }
}

void Game::Reset()
{
    mSpace.reset(new Space());
    LOG(INFO) << "Reset";
}
