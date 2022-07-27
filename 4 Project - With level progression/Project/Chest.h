#pragma once
#include "PlacableActor.h"
#include "Money.h"

enum class ChestState
{
	Closed,
	Open,
	Used
};

class Chest : public PlacableActor
{

public:
	Chest(int x, int y, Money money);
	virtual void Draw() override;

	Money GetMoney() { return m_money; }

	virtual ActorType GetType() override { return ActorType::Chest; }
	ChestState GetChestState() { return m_chestState; }
	void SetChestState();

private:
	Money m_money;
	ChestState m_chestState;
};