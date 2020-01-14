#pragma once
#include"State.h"
#include"Button.h"

#include<stack>

class SelectPlayerState :public State
{
public:
	SelectPlayerState(sf::RenderWindow& window,std::vector<State*>& childStates,std::stack<State*>& parentStates);
	void update();
	void updateSFMLEvents();
	void render();
	void endState();
private:

	//InitFunction
	void initSelectPlayerState();
	void initPersonTabs();
	void initButtons();
	bool initFont();
	void initPlayerTabsName();
	void initStartGameButton();

	//Update
	void updatePersonTabs();
	void updatePersonTabsPosition();
	void updatePersonTabsNamePosition();
	void updatePersonTabsNameTextPosition();
	void updatePersonTextNameString();
	void updateStartGameButtonPosition();
	void updateStartGameButtonState();
	void updateStartGameButton();


	void updateButtons();
	void updatePositionButtons();
	void updateStateButtons();
	void updateHoverSelectPlayerButtons();
	void updatePersonTabsTexture();

	//Rend
	void rendPersonTabs();
	void rendSelectRoleButtons();
	void rendPersonTabsNameShape();
	void rendPersonName();
	void rendStartGameButton();

private:
	std::vector<std::pair<sf::RectangleShape, sf::Texture*>> m_playerTabsTexture;
	std::vector<std::pair<sf::RectangleShape, sf::Text>> m_playerTabsName;

	std::vector<Button*> m_selectRoleButtons;
	sf::Font m_font;
	std::vector<State*>& m_childStates;
	std::stack<State*>& m_parentStates;
	sf::String playerName;
	Button* m_startGameButton;
};