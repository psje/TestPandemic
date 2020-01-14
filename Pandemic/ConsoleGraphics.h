#pragma once
#include"BoardData.h"
#include"EVirus.h"
#include"Player.h"
class ConsoleGraphics
{
public:
	void DisplayBoard(const BoardData& board,const std::vector<Player>& allPlayers) const;
};

