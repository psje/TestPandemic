#include "SelectPlayerState.h"

#include "SelectRoleState.h"

#include "GameState.h"

#include<iostream>

SelectPlayerState::SelectPlayerState(sf::RenderWindow& window,std::vector<State*>& childStates,std::stack<State*>& parentStates):
	State(window),
	m_childStates(childStates),
	m_parentStates(parentStates)
{
	initSelectPlayerState();
}

void SelectPlayerState::update()
{
	updateButtons();
	updatePersonTabs();
	updatePersonTabsNamePosition();
	updatePersonTabsNameTextPosition();
	updatePersonTextNameString();
	updateStartGameButton();
}

void SelectPlayerState::updateSFMLEvents()
{
	while (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_window.close();
		else if (m_event.type == sf::Event::TextEntered)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::BackSpace))
			{
				if(playerName.getSize()>=1)
				playerName.erase(playerName.getSize() - 1);
			}
			else
			{
				playerName += m_event.text.unicode;
			}
		}
	}
}

void SelectPlayerState::render()
{
	rendPersonTabs();
	rendSelectRoleButtons();
	rendPersonTabsNameShape();
	rendPersonName();
	rendStartGameButton();
}

void SelectPlayerState::endState()
{
}

void SelectPlayerState::initSelectPlayerState()
{
	initFont();
	initPersonTabs();
	initButtons();
	initPlayerTabsName();
	initStartGameButton();
}

void SelectPlayerState::initPersonTabs()
{
	sf::Texture* anonymousPersonTexture;
	anonymousPersonTexture = new sf::Texture();
	anonymousPersonTexture->loadFromFile("Res//Anonymous.png");

	m_playerTabsTexture.push_back(std::pair<sf::RectangleShape, sf::Texture*>());
	m_playerTabsTexture.push_back(std::pair<sf::RectangleShape, sf::Texture*>());

	m_playerTabsTexture[0].second = anonymousPersonTexture;

	sf::RectangleShape shape;
	shape.setOutlineColor(sf::Color::Cyan);
	shape.setOutlineThickness(5);
	shape.setSize(sf::Vector2f(100, 100));
	shape.setTexture(m_playerTabsTexture[0].second);


	m_playerTabsTexture[0].first = shape;

	m_playerTabsTexture[1].second = anonymousPersonTexture;
	m_playerTabsTexture[1].first = shape;
}

void SelectPlayerState::initButtons()
{
	m_selectRoleButtons.push_back(new Button(sf::Vector2f(0, 0), sf::Vector2f(100, 30), "select role", m_font, sf::Color::Blue,
		3, sf::Color::Cyan));

	m_selectRoleButtons.push_back(new Button(sf::Vector2f(0, 0), sf::Vector2f(100, 30), "select role", m_font, sf::Color::Blue,
		3, sf::Color::Cyan));
}

bool SelectPlayerState::initFont()
{
	m_font.loadFromFile("Res//Fonts//OpenSans-Bold.ttf");
	return true;
}

void SelectPlayerState::initPlayerTabsName()
{
	sf::RectangleShape tabName1(sf::Vector2f(100,30));
	sf::RectangleShape tabName2(sf::Vector2f(100, 30));

	tabName1.setOutlineThickness(5);
	tabName1.setOutlineColor(sf::Color::Cyan);

	tabName2.setOutlineThickness(5);
	tabName2.setOutlineColor(sf::Color::Cyan);

	sf::Text text1;
	text1.setFont(m_font);
	text1.setString("mama");
	text1.setCharacterSize(15);
	text1.setColor(sf::Color::Black);
	sf::Text text2;

	m_playerTabsName.push_back(std::make_pair(tabName1, text1));
	m_playerTabsName.push_back(std::make_pair(tabName2, text2));
}

void SelectPlayerState::initStartGameButton()
{
	m_startGameButton = new Button(sf::Vector2f(0, 0), sf::Vector2f(140, 30), "Begin Game", m_font, sf::Color::Blue,
		3, sf::Color::Cyan);
}

void SelectPlayerState::updatePersonTabs()
{
	updatePersonTabsPosition();
	updatePersonTabsTexture();
}

void SelectPlayerState::updatePersonTabsPosition()
{
	sf::Vector2f position;
	position.x = m_window.getView().getCenter().x - 2 * m_playerTabsTexture[0].first.getSize().x;
	position.y = m_window.getView().getCenter().y - m_playerTabsTexture[0].first.getSize().y;

	m_playerTabsTexture[0].first.setPosition(position);

	position.x += 3 * m_playerTabsTexture[0].first.getSize().x;
	m_playerTabsTexture[1].first.setPosition(position);
}

void SelectPlayerState::updatePersonTabsNamePosition()
{
	m_playerTabsName[0].first.setPosition(m_selectRoleButtons[0]->GetPosition().x, m_selectRoleButtons[0]->GetPosition().y + 55);
	m_playerTabsName[1].first.setPosition(m_selectRoleButtons[1]->GetPosition().x, m_selectRoleButtons[1]->GetPosition().y + 55);
}

void SelectPlayerState::updatePersonTabsNameTextPosition()
{
	for(int index=0;index<m_selectRoleButtons.size();index++)
	m_playerTabsName[index].second.setPosition(m_selectRoleButtons[index]->GetPositionText().x,m_selectRoleButtons[index]->GetPosition().y+55);
}

void SelectPlayerState::updatePersonTextNameString()
{
	m_playerTabsName[0].second.setString(playerName);
}

void SelectPlayerState::updateStartGameButtonPosition()
{
	sf::Vector2f position;
	position.x = m_window.getView().getCenter().x + 200;
	position.y = m_window.getView().getCenter().y + 200;

	if (m_startGameButton != nullptr)
		m_startGameButton->UpdatePosition(position);
}

void SelectPlayerState::updateStartGameButtonState()
{
	m_startGameButton->UpdateState(m_window);

	if (m_startGameButton->IsPressed())
	{
		m_childStates.clear();
		m_parentStates.push(new GameState(m_window));
	}
}

void SelectPlayerState::updateStartGameButton()
{
	updateStartGameButtonPosition();
	updateStartGameButtonState();
}

void SelectPlayerState::updateButtons()
{
	updatePositionButtons();
	updateHoverSelectPlayerButtons();
	updateStateButtons();
}

void SelectPlayerState::updatePositionButtons()
{
	for (int index = 0; index < m_selectRoleButtons.size(); index++)
	{
		sf::Vector2f position;
		position.x = m_playerTabsTexture[index].first.getPosition().x + m_playerTabsTexture[index].first.getSize().x + 20;
		position.y = m_playerTabsTexture[index].first.getPosition().y;
		m_selectRoleButtons[index]->UpdatePosition(position);
	}
}

void SelectPlayerState::updateStateButtons()
{
	for (int index = 0; index < m_selectRoleButtons.size(); index++)
		if (m_selectRoleButtons[index]->IsPressed())
		{
			m_childStates.push_back(new SelectRoleStates(m_window, m_childStates,m_playerTabsTexture[index].second));
			return;
		}
}

void SelectPlayerState::updateHoverSelectPlayerButtons()
{
	for (int index = 0; index < m_selectRoleButtons.size(); index++)
		m_selectRoleButtons[index]->UpdateState(m_window);
}

void SelectPlayerState::updatePersonTabsTexture()
{
	for (int index = 0; index < m_playerTabsTexture.size(); index++)
		m_playerTabsTexture[index].first.setTexture(m_playerTabsTexture[index].second,true);
}

void SelectPlayerState::rendPersonTabs()
{
	m_window.draw(m_playerTabsTexture[0].first);
	m_window.draw(m_playerTabsTexture[1].first);
}

void SelectPlayerState::rendSelectRoleButtons()
{
	for (int index = 0; index < m_selectRoleButtons.size(); index++)
		m_selectRoleButtons[index]->Rend(m_window);
}

void SelectPlayerState::rendPersonTabsNameShape()
{
	for(int index=0;index<m_playerTabsName.size();index++)
	m_window.draw(m_playerTabsName[index].first);
}

void SelectPlayerState::rendPersonName()
{
	for (int index = 0; index < m_playerTabsName.size(); index++)
		m_window.draw(m_playerTabsName[index].second);
}

void SelectPlayerState::rendStartGameButton()
{
	m_startGameButton->Rend(m_window);
}
