#include "GameState.h"

GameState::GameState(sf::RenderWindow& window):State(window)
{
	m_window.setView(sf::View(sf::FloatRect(0, 0, 1920, 1080)));

	initBackground();
	initFont();
	initBlueRound();
	initRedRound();
	initYellowRound();
	initBlackRound();
	initCities();
	initLines();
}

void GameState::update()
{
	updateBlueRounds();
	for (int index = 0; index < m_cities.size(); index++)
		m_cities[index].Update(m_window);
}

void GameState::render()
{
	rendBackground();
	rendCities();
	rendLines();
	rendStatsTableBoard();
}

void GameState::endState()
{
}

void GameState::updateSFMLEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}

bool GameState::initBackground()
{
	sf::Texture backgroundTexture;

	if (!backgroundTexture.loadFromFile("Res//Background.png"))
		throw("could not load background");

	m_textures["background"] = backgroundTexture;

	sf::Sprite backgroundSprite(m_textures["background"]);

	m_sprites["background"] = backgroundSprite;

	return true;
}

bool GameState::initBlueRound()
{
	sf::Texture blueRoundTexture;

	if (!blueRoundTexture.loadFromFile("Res//Rounds//Pan_Blue_Circle.png"))
		throw("could not load blue round");

	m_textures["blue_round"] = blueRoundTexture;

	sf::Sprite blueRoundSprite(m_textures["blue_round"]);
	blueRoundSprite.setScale(0.08,0.08);
	blueRoundSprite.setPosition(300,500);

	m_rounds["blue_round"] = blueRoundSprite;
}

bool GameState::initRedRound()
{
	sf::Texture redRoundTexture;

	if (!redRoundTexture.loadFromFile("Res//Rounds//Pan_Red_Circle.png"))
		throw("could not load red round texture");

	m_textures["red_round"] = redRoundTexture;

	sf::Sprite redRoundSprite(m_textures["red_round"]);
	redRoundSprite.setScale(0.02, 0.02);
	redRoundSprite.setPosition(500, 500);

	m_rounds["red_round"] = redRoundSprite;
}

bool GameState::initYellowRound()
{
	sf::Texture yellowRoundTexture;

	if (!yellowRoundTexture.loadFromFile("Res//Rounds//Pan_Yellow_Circle.png"))
		throw("could not load yellow round texture");

	m_textures["yellow_round"] = yellowRoundTexture;

	sf::Sprite yellowRoundSprite(m_textures["yellow_round"]);
	yellowRoundSprite.setScale(0.05, 0.05);
	yellowRoundSprite.setPosition(600, 600);

	m_rounds["yellow_round"] = yellowRoundSprite;
}

bool GameState::initBlackRound()
{
	sf::Texture blackRoundTexture;

	if (!blackRoundTexture.loadFromFile("Res//Rounds//Pan_Black_Circle.png"))
		throw("could not load black round texture");

	m_textures["black_round"] = blackRoundTexture;

	sf::Sprite blackRoundSprite(m_textures["black_round"]);
	blackRoundSprite.setScale(0.1,0.1);
	blackRoundSprite.setPosition(700,700);

	m_rounds["black_round"] = blackRoundSprite;
}

bool GameState::initCities()
{
	sf::Text text;
	text.setFont(m_font);
	text.setString("BEIJING");
	text.setCharacterSize(17);

	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[0].SetPosition(sf::Vector2i(1300,400));

	text.setString("SEOUL");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[1].SetPosition(sf::Vector2i(1500,380));

	text.setString("SHANGAI");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[2].SetPosition(sf::Vector2i(1420,490));

	text.setString("TOKYO");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[3].SetPosition(sf::Vector2i(1560,470));

	text.setString("HONG KONG");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[4].SetPosition(sf::Vector2i(1400,600));

	text.setString("TAIPEI");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[5].SetPosition(sf::Vector2i(1550,560));

	text.setString("OSAKA");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[6].SetPosition(sf::Vector2i(1700,520));

	text.setString("BANGKOK");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[7].SetPosition(sf::Vector2i(1350,650));

	text.setString("HO CHI MINH CITY");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[8].SetPosition(sf::Vector2i(1450,720));

	text.setString("MANILA");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[9].SetPosition(sf::Vector2i(1550,680));

	text.setString("SYDENEY");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[10].SetPosition(sf::Vector2i(1600,900));

	text.setString("JAKARTA");
	m_cities.push_back(BoardCity(m_rounds["red_round"], text));
	m_cities[11].SetPosition(sf::Vector2i(1400,780));

	text.setString("KOLKOTA");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[12].SetPosition(sf::Vector2i(1300,520));

	text.setString("CHENNAI");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[13].SetPosition(sf::Vector2i(1250,670));

	text.setString("MUMBAI");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[14].SetPosition(sf::Vector2i(1150,620));

	text.setString("DELHI");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[15].SetPosition(sf::Vector2i(1200,490));

	text.setString("KARACHI");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[16].SetPosition(sf::Vector2i(1120,540));

	text.setString("RIYADH");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[17].SetPosition(sf::Vector2i(1050,590));

	text.setString("BAGHDAD");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[18].SetPosition(sf::Vector2i(1050,480));

	text.setString("TEHERAN");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[19].SetPosition(sf::Vector2i(1100,400));

	text.setString("MOSCOW");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[20].SetPosition(sf::Vector2i(1000,400));

	text.setString("ISTANBUL");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[21].SetPosition(sf::Vector2i(960,490));

	text.setString("CAIRO");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[22].SetPosition(sf::Vector2i(960,590));

	text.setString("ALGERS");
	m_cities.push_back(BoardCity(m_rounds["black_round"], text));
	m_cities[23].SetPosition(sf::Vector2i(830,550));

	text.setString("LAGOS");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[24].SetPosition(sf::Vector2i(830,650));

	text.setString("KHARTOUM");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[25].SetPosition(sf::Vector2i(970,670));

	text.setString("KINSHASA");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[26].SetPosition(sf::Vector2i(900,730));

	text.setString("JOHANNESBURG");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[27].SetPosition(sf::Vector2i(1000,780));

	text.setString("SAO PAULO");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[28].SetPosition(sf::Vector2i(650,840));

	text.setString("BUENOS AIRES");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[29].SetPosition(sf::Vector2i(600,900));

	text.setString("SANTIAGO");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[30].SetPosition(sf::Vector2i(470, 920));

	text.setString("LIMA");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[31].SetPosition(sf::Vector2i(470,800));

	text.setString("BOGOTA");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[32].SetPosition(sf::Vector2i(490,700));

	text.setString("MIAMI");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[33].SetPosition(sf::Vector2i(490,610));

	text.setString("MEXICO CITY");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[34].SetPosition(sf::Vector2i(380,630));

	text.setString("LOS ANGELES");
	m_cities.push_back(BoardCity(m_rounds["yellow_round"], text));
	m_cities[35].SetPosition(sf::Vector2i(310,560));

	text.setString("SAN FRANCISCO");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text));
	m_cities[36].SetPosition(sf::Vector2i(280,470));

	text.setString("CHICAGO");
	m_cities.push_back(BoardCity(m_rounds["blue_round"],text));
	m_cities[37].SetPosition(sf::Vector2i(400,420));

	text.setString("MONTREAL");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text));
	m_cities[38].SetPosition(sf::Vector2i(500,440));

	text.setString("WASHINGTON");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text));
	m_cities[39].SetPosition(sf::Vector2i(530,520));

	text.setString("NEW YORK");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text));
	m_cities[40].SetPosition(sf::Vector2i(620,450));

	text.setString("ATALANTA");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text));
	m_cities[41].SetPosition(sf::Vector2i(420, 520));

	text.setString("LONDON");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text));
	m_cities[42].SetPosition(sf::Vector2i(750,370));

	text.setString("MADRID");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text));
	m_cities[43].SetPosition(sf::Vector2i(740,520));

	text.setString("PARIS");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text));
	m_cities[44].SetPosition(sf::Vector2i(800,440));

	text.setString("MILAN");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text));
	m_cities[45].SetPosition(sf::Vector2i(900,460));

	text.setString("ESSEN");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text));
	m_cities[46].SetPosition(sf::Vector2i(900,360));

	text.setString("ST PETESBURG");
	m_cities.push_back(BoardCity(m_rounds["blue_round"], text));
	m_cities[47].SetPosition(sf::Vector2i(1000,330));

	return true;
}

bool GameState::initLines()
{

	return true;
}

bool GameState::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
	return true;
}

void GameState::rendBackground()
{
	m_window.draw(m_sprites["background"]);
}

void GameState::rendBlueRound()
{
	m_window.draw(m_rounds["blue_round"]);
}

void GameState::rendRedRound()
{
	m_window.draw(m_rounds["red_round"]);
}

void GameState::rendYellowRound()
{
	m_window.draw(m_rounds["yellow_round"]);
	m_window.draw(m_rounds["black_round"]);
}

void GameState::rendCities()
{
	for (int index = 0; index < m_cities.size(); index++)
		m_cities[index].Rend(m_window);
}

void GameState::rendLines()
{
	for (int index = 0; index < m_lines.size(); index++)
		m_lines[index].Rend(m_window);
}

void GameState::rendStatsTableBoard()
{
	m_statsTableBoard.Rend(m_window);
}

void GameState::updateBlueRounds()
{
	//for (int index = 0; index < m_blueRounds.size(); index++)
	//	if (index == 0)
	//		m_blueRounds[index].setPosition(100, 100);
}
