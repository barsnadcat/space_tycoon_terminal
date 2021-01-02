#include <Game.h>
#include <ObjectiveUtilitiesConfig.h>
#include <ProductionsConfig.h>
#include <easylogging++.h>

Game::Game()
{
	mUpdateContext.mObjectiveUtilities = GetObjectiveUtilities();
	mUpdateContext.mProductions = GetProductions();
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
	LOG(INFO) << mUpdateContext.mCurrentTime
	          << " Food:" << mSettlement->GetFoods().size()
	          << " People:" << mSettlement->GetPeople().size()
	          << " Farm:" << mSettlement->GetFarms().size();
}

void Game::Reset()
{
	mSettlement.reset(new Settlement());
	mSettlement->AddPerson(std::make_shared<Person>(30000, 100, RandomPreferences(mUpdateContext)));
	LOG(INFO) << "Reset";
}
