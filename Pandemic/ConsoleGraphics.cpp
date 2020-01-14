#include "ConsoleGraphics.h"



void ConsoleGraphics::DisplayBoard(const BoardData& board,const std::vector<Player>& allPlayers) const
{	
	
	auto index = 0;
	for (auto it : board.GetCities()) {
		++index;
		std::cout << "[" << it.GetCityId() << "," << it.GetCityName() << "]"
			<< "[" << it.GetNumberOfViruses(EVirus::BlackVirus) << "," << it.GetNumberOfViruses(EVirus::BlueVirus) << "," <<
			it.GetNumberOfViruses(EVirus::RedVirus) << "," << it.GetNumberOfViruses(EVirus::YellowVirus) << "]"
			<< "[" << it.GetResearchStationStatus() << "]";
		if (index % 4 == 0) {
			std::cout << "\n";
		}
		for (auto i = 0; i < allPlayers.size(); ++i) {
			if (allPlayers[i].GetCurentCity().GetCityName() == it.GetCityName()) {
				std::cout << "[" << allPlayers[i].GetPlayerName() << "]";
			}
		}
		std::cout<< "      " <<"\n";
	}
	
	
	
	
}
