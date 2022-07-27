#include <iostream>
#include <Windows.h>
#include "Chest.h"

Chest::Chest(int x, int y, Money* money)
	: PlacableActor(x, y)
	, m_money(money)
	, m_chestState(ChestState::Closed)
{

}

void Chest::SetChestState()
{
	if (m_chestState == ChestState::Closed) {
		m_chestState = ChestState::Open;
	}
	else if(m_chestState == ChestState::Open)
	{
		m_chestState = ChestState::Used;
	}
	else
	{
		// Do nothing if chest is used
	}
}

void Chest::Draw()
{
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);

	if (m_chestState == ChestState::Closed)
	{
		// draw a block
		std::cout << (char)219;
	}
	else if (m_chestState == ChestState::Open)
	{
		SetConsoleTextAttribute(console, (int)ActorColor::Regular);
		m_money->Draw();
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
		std::cout << (char)223;
	}
	else
	{

		std::cout << (char)223;
	}
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}