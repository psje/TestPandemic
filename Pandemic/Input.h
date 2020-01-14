#pragma once
#include<iostream>
#include"City.h"
#include"BoardData.h"
#include"Player.h"
#include"CityCard.h"
class Input
{
private:
	int16_t m_action=0;
	int16_t m_playerNumber=0;
	int16_t m_inputCity ;
	int16_t m_selectedCard;
	EVirus m_selectedVirus;
public:
	
	const int16_t GetCard() const { return m_selectedCard; }
	const EVirus GetVirus() const;
	City& GetCity(BoardData& board);
	void SetVirus();
	void SetPlayerNumber();
	void SetCard();
	void ChooseInput();
	int16_t GetAction() const { return m_action; }
	int16_t GetPlayerNumber() const { return m_playerNumber; }
	int16_t GetInputCity() const { return m_inputCity; }
	void PrintInput()const ;
};

