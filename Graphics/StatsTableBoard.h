#pragma once
#include"SFML/Graphics.hpp"

#include"StatsVirusBoard.h"
#include"StatsDeckBoard.h"

#include<map>
#include<string>

class StatsTableBoard
{
public:
	StatsTableBoard();
	void Rend(sf::RenderTarget& target);
private:
	void initBlackBox();
	void initRedVirus();
	void initBlueVirus();
	void initGreyVirus();
	void initYellowVirus();

	void initDecks();

	void initFont();

	void initInfectionRateText();
private:
	sf::RectangleShape m_blackBox;

	StatsVirusBoard* m_redVirus;
	StatsVirusBoard* m_blueVirus;
	StatsVirusBoard* m_greyVirus;
	StatsVirusBoard* m_yellowVirus;

	StatsDeckBoard* m_deck;

	sf::Text m_text_InfectionRate;

	sf::Font m_font;
};