#pragma once

#include"PlayerData.h"
#include<algorithm>
#include"Input.h"

class Player:public PlayerData
{
public:
	Player(const std::string playerName, const int16_t playerNumber, City& originalCity) :
		PlayerData(playerName, playerNumber, originalCity)
	{}
	
	void FerryMove(City& nextCity);
	void FlightMove(City& nextCity);
	void CharterMove(City& nextCity);
	void ShuttleMove(City& nextCity);
	void BuildResearchStation();
	void TreatDesease(const EVirus virus);
	void ShareKnowledge(const Player& p2,CityCard&& c1);
	void DiscoverCure(EVirus virus);
	
};

