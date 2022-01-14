#include <Game.h>
#include <Land.h>
#include <Food.h>
#include <Farm.h>
#include <ObjectiveUtilitiesConfig.h>
#include <ProductionsConfig.h>
#include <easylogging++.h>

Game::Game()
{
	mUpdateContext.mObjectiveUtilities = GetObjectiveUtilities();
	mUpdateContext.mProductions = GetProductions();
	Reset(100);
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
	std::stringstream res;
	for (size_t i = 0; i < mSettlement->GetLands().size(); i++)
	{
		Land& l = mSettlement->GetLand(i);
		RenderLand(l, res);
	}

	LOG(INFO) << mUpdateContext.mCurrentTime << " " << res.str();
}

void Game::RenderLand(Land& l, std::stringstream& res) const
{
	int32_t of = 0;
	int32_t uf = 0;
	for (auto* p : l.GetFoods())
	{
		p->GetPerson() ? of++ : uf++;
	}
	res << "|" << (l.GetFarm() == nullptr ? "_" : l.GetFarm()->GetPerson() == nullptr ? "f" : "F")
	    << ",f:" << of << "/" << uf;
	for (Person* p : l.GetPeople())
	{
		RenderPerson(p, res);
	}
}

void Game::RenderPerson(Person* p, std::stringstream& res) const
{
	res << " P:" << p->GetHealth() << "/" << p->GetMaxHealth()
	    << ",e:" << p->GetEnergy() << ",c:" << p->GetChildren()
	    << ",f:" << p->GetFoods().size() << (p->GetFarm() == nullptr ? ",_" : ",F");
}

void Game::Reset(int n)
{
	mSettlement.reset(new Settlement(n));
	new Person(&(mSettlement->GetLand(0)), 30000, 100, RandomPreferences(mUpdateContext));
	LOG(INFO) << "Reset";
}
