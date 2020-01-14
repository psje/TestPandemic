#include "StatsTableBoard.h"

StatsTableBoard::StatsTableBoard()
{
	initBlackBox();

	initRedVirus();
	initBlueVirus();
	initGreyVirus();
	initYellowVirus();

	initDecks();

	initFont();

	initInfectionRateText();
}

void StatsTableBoard::Rend(sf::RenderTarget& target)
{
	target.draw(m_blackBox);

	m_redVirus->Render(target);
	m_blueVirus->Render(target);
	m_greyVirus->Render(target);
	m_yellowVirus->Render(target);

	m_deck->Render(target);

	target.draw(m_text_InfectionRate);
}

void StatsTableBoard::initBlackBox()
{
	m_blackBox.setFillColor(sf::Color::Black);
	m_blackBox.setSize(sf::Vector2f(700,200));
	m_blackBox.setPosition(sf::Vector2f(600,0));
	m_blackBox.setOutlineThickness(4);
	m_blackBox.setOutlineColor(sf::Color::White);
}

void StatsTableBoard::initRedVirus()
{
	m_redVirus = new StatsVirusBoard("Res//Square//RedSquare.png");

	m_redVirus->SetPosition(sf::Vector2f(750, 10));
}

void StatsTableBoard::initBlueVirus()
{
	m_blueVirus = new StatsVirusBoard("Res//Square//BlueSquare.png");

	m_blueVirus->SetPosition(sf::Vector2f(m_redVirus->GetPosition().x+100,m_redVirus->GetPosition().y));
}

void StatsTableBoard::initGreyVirus()
{
	m_greyVirus = new StatsVirusBoard("Res//Square//GreySquare.png");

	m_greyVirus->SetPosition(sf::Vector2f(m_blueVirus->GetPosition().x + 100, m_blueVirus->GetPosition().y));

	m_greyVirus->SetScale(0.04, 0.04);
}

void StatsTableBoard::initYellowVirus()
{
	m_yellowVirus = new StatsVirusBoard("Res//Square//YellowSquare.png");

	m_yellowVirus->SetPosition(sf::Vector2f(m_greyVirus->GetPosition().x + 100, m_greyVirus->GetPosition().y));
}

void StatsTableBoard::initDecks()
{
	m_deck = new StatsDeckBoard("Res//Cards//Blue Back Cards.png");

	m_deck->SetPosition(sf::Vector2f(m_redVirus->GetPosition().x - 130, m_redVirus->GetPosition().y));
}

void StatsTableBoard::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
}

void StatsTableBoard::initInfectionRateText()
{
	m_text_InfectionRate.setFont(m_font);

	m_text_InfectionRate.setString("Infection Rate");

	m_text_InfectionRate.setPosition(870,70);

	m_text_InfectionRate.setColor(sf::Color::Green);

	m_text_InfectionRate.setCharacterSize(25);
}
