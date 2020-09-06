#include <Game.h>
#include <easylogging++.h>

Game::Game()
{
    Reset();
}

void Game::Run(int n)
{
	for (int i = 0; i < n; i++)
	{
		mUpdateContext.mCurrentTime++;
		mSettlement->Update(mUpdateContext);
	}
	Render();
}

void Game::Render() const
{
	LOG(INFO) << mUpdateContext.mCurrentTime << " F:" << mSettlement->GetFoods().size() << " P:" << mSettlement->GetPeople().size();
}

void Game::Reset()
{
	mSettlement.reset(new Settlement());
    mSettlement->AddPerson(std::make_unique<Person>(30000, 10));
	LOG(INFO) << "Reset";
}
