#pragma once
#include"State.h"
#include"BoardCity.h"
#include"Lines.h"
#include"StatsTableBoard.h"

#include<map>

class GameState :public State
{
public:
	GameState(sf::RenderWindow& window);

	void update() override;
	void render() override;
	void endState() override;
	void updateSFMLEvents() override;
private:
	bool initBackground();
	bool initBlueRound();
	bool initRedRound();
	bool initYellowRound();
	bool initBlackRound();
	bool initCities();
	bool initLines();
	bool initFont();
private:
	void rendBackground();
	void rendBlueRound();
	void rendRedRound();
	void rendYellowRound();
	void rendCities();
	void rendLines();
	void rendStatsTableBoard();
private:
	void updateBlueRounds();
private:
	std::map<std::string, sf::Sprite> m_rounds;
	sf::Font m_font;
	std::map<std::string, sf::Text>m_texts;

	StatsTableBoard m_statsTableBoard;

	std::vector<BoardCity> m_cities;
	std::vector<Line> m_lines;
};