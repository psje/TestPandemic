#include"Gameplay.h"
#include<string>
#include"EventActions.h"
#include"AI.h"
#include<algorithm>
void Gameplay::InitializeGame(std::vector<Player>& allPlayers,Deck& playerDeck,Deck& DiscardedInfectionDeck,Deck& infectionDeck,BoardData& board)
{
	
	board.GenerateBoard();
	board.SetCitiesNeibours();
	playerDeck.GenerateDeck();
	infectionDeck.GenerateDeck();
	board.GetCity(2).SetResearchStation(true);
	playerDeck.ShuffleTheDeck();
	infectionDeck.ShuffleTheDeck();
	GeneratePlayers(2, allPlayers, board);
	SplitPlayerCards(allPlayers,playerDeck);
	InfectCities(infectionDeck,DiscardedInfectionDeck, board);
	

}
void Gameplay::GeneratePlayers(int16_t numberOfPlayers, std::vector<Player>& allPlayers, BoardData& board)
{
	for (int i = 0; i < numberOfPlayers; i++) {

		allPlayers.emplace_back(Player("Player"+std::to_string(i+1), i, board.GetCity(2)));
	}

}

void Gameplay::CardDraw(int playerNumber,Deck& playerDeck, std::vector<Player>& allPlayers,int& k, Deck& DiscardedInfectionDeck, Deck& infectionDeck, BoardData& board)
{
	
	for (int j = 0; j < 2; j++) {
		auto selection = playerDeck.ChooseCardToDraw();
		if (selection == 0) {
			auto curentCard = playerDeck.GetTopCard();
			allPlayers[playerNumber].AddCityCard(curentCard);
		}
		else if (selection == 1) {
			allPlayers[playerNumber].AddEventCard(EventCard(k));
			++k;
		}
		else {
			InfectionCardActions(board,infectionDeck,DiscardedInfectionDeck);
		}
	}
}

bool Gameplay::EventCardHandler(std::vector<Player>& allPlayers,int16_t playerNumber, Deck& DiscardedInfectionDeck, Deck& infectionDeck, BoardData& board)
{
	bool EventCardManager;
	int eventCard;
	std::cout << "Do you want to play an event card?";
	std::cin >> EventCardManager;
	if (EventCardManager) {
		std::cout << "The card you want to play is?";
		std::cin >> eventCard;

		if (eventCard == 5) {
			return true;
		}
		else {
			ChoseEventActions(allPlayers[playerNumber].GetEventCard(eventCard),allPlayers,DiscardedInfectionDeck,infectionDeck,board);
			return false;
		}
	}
}

void Gameplay::SelectAction(Player& player, Input& userInput,BoardData& board, std::vector<Player>& allPlayers){

	switch (userInput.GetAction())
	{
	case 1: {

		player.FerryMove(userInput.GetCity(board));
		break;
	}

	case 2: {
		player.FlightMove(userInput.GetCity(board));
		break;
	}
	case 3: {

		player.CharterMove(userInput.GetCity(board));
		break;
	}
	case 4: {
		player.FlightMove(userInput.GetCity(board));
		break;
	}
	case 5: {
		player.BuildResearchStation();
		break;
	}
	case 6: {
		userInput.SetVirus();
		player.TreatDesease(userInput.GetVirus());
		break;
	}
	case 7: {
		userInput.SetPlayerNumber();
		userInput.SetCard();
		allPlayers[userInput.GetPlayerNumber()].AddCityCard(player.GetCard(userInput.GetCard()));
	}
	case 8: {
		player.TreatDesease(userInput.GetVirus());
	}
	default: {
		break;
	}
	}

}

void Gameplay::SplitPlayerCards(std::vector<Player>& allPlayers, Deck& playerDeck)
{

	if (allPlayers.size() == 4) {
		for(int i = 0; i < allPlayers.size(); i++) {
			allPlayers[i].AddCityCard(playerDeck.GetTopCard());
			allPlayers[i].AddCityCard(playerDeck.GetTopCard());
		}
	}else if (allPlayers.size() == 3) {
		for (int i = 0; i < allPlayers.size(); i++) {
			allPlayers[i].AddCityCard(playerDeck.GetTopCard());
			allPlayers[i].AddCityCard(playerDeck.GetTopCard());
			allPlayers[i].AddCityCard(playerDeck.GetTopCard());
		}
	}
	else {
		for (int i = 0; i < allPlayers.size(); i++) {
			allPlayers[i].AddCityCard(playerDeck.GetTopCard());
			allPlayers[i].AddCityCard(playerDeck.GetTopCard());
			allPlayers[i].AddCityCard(playerDeck.GetTopCard());
			allPlayers[i].AddCityCard(playerDeck.GetTopCard());
		}
	}
}

void Gameplay::InfectCities(Deck& infectionDeck, Deck& DiscardedInfectionDeck, BoardData& board)
{
	for (int i = 3; i > 0; --i) {
		for (int j = 0; j < 3; ++j) {
			auto curentCard = infectionDeck.GetTopCard();
			DiscardedInfectionDeck.AddCard(curentCard);
			board.GetCity(curentCard.GetCityId()).SetDisease(curentCard.GetVirus(), i);
		}
	}

}

void Gameplay::InfectionCardActions(BoardData& board, Deck& infectionDeck, Deck& DiscardedInfectionDeck)
{
	board.AdvanceInfectionMarker();
	auto topCard = infectionDeck.GetTopCard();
	DiscardedInfectionDeck.AddCard(topCard);
	board.GetCity(topCard.GetCityId()).SetDisease(topCard.GetVirus(),3);
	infectionDeck.AddCard(DiscardedInfectionDeck.GetTopCard());
}

void Gameplay::ChoseEventActions(EventCard eCard, std::vector<Player>& allPlayers, Deck& DiscardedInfectionDeck, Deck& infectionDeck, BoardData& board){
	switch (eCard.GetId())
	{
	case 1: {
		EventActions::Event1(infectionDeck);
		break;
	}
	case 2: {
		EventActions::Event2(DiscardedInfectionDeck);
		break;
	}
	case 3: {
		EventActions::Event3(allPlayers, board);
		break;
	}
	case 4: {
		EventActions::Event4(board);
		break;
	}
	case 5: {
		
	}

	default:
		break;
	}
	
}




void Gameplay::StartGame()
{
	
	std::vector<Player> allPlayers;
	Input userInput;
	Deck playerDeck;
	Deck DiscardedInfectionDeck;
	Deck infectionDeck;
	BoardData board;
	ConsoleGraphics c;
	InitializeGame(allPlayers, playerDeck, DiscardedInfectionDeck, infectionDeck, board);
	c.DisplayBoard(board, allPlayers);
	
	auto running = true;
	const auto numberOfActions = 4;
	auto k = 0;
	
	AI ai;
	ai.MakePrediction(board, allPlayers[0], infectionDeck);

	while (running) {

		for (auto i = 0; i < allPlayers.size(); ++i) {
			for (auto j = 0; j < numberOfActions; ++j) {
				std::cout << "Player" << i+1 <<" Action " <<j+1<< "\n"; //temporary
				userInput.ChooseInput(); 
				userInput.GetCity(board);
				SelectAction(allPlayers[i],userInput,board,allPlayers);
				c.DisplayBoard(board,allPlayers); //temporary
			}

			CardDraw(i, playerDeck, allPlayers,k,DiscardedInfectionDeck,infectionDeck,board);
			auto index=EventCardHandler(allPlayers, i,DiscardedInfectionDeck,infectionDeck,board);
			
			if (!index) {

				for (int i = 0; i < board.GetInfectionRate(); i++) {
					auto curentCard = infectionDeck.GetTopCard();
					DiscardedInfectionDeck.AddCard(curentCard);
					board.GetCity(curentCard.GetCityId()).SetDisease(curentCard.GetVirus(), 2);

				}
			}
			

		}

		
				
		

		std::cout << "Do you want to continue" << std::endl;
		std::cin >> running;
		std::cin.clear();
		system("cls");

	}
}

const bool Gameplay::WiningCondition(BoardData& board) const
{
	auto curedBlack = board.GetCuredMarkers(EVirus::BlackVirus);
	auto curedBlue = board.GetCuredMarkers(EVirus::BlueVirus);
	auto curedYellow = board.GetCuredMarkers(EVirus::YellowVirus);
	auto curedRed = board.GetCuredMarkers(EVirus::RedVirus);
	if (curedBlack == 1 && curedBlue == 1 && curedRed == 1 && curedYellow == 1) {
		return true;
	}
	else {
		return false;
	}
}
