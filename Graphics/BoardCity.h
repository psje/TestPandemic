#pragma once
#include"SFML/Graphics.hpp"

class BoardCity
{
public:
	BoardCity(sf::Sprite& circle, sf::Text& text);
	void Rend(sf::RenderTarget& target);
	void SetPosition(const sf::Vector2i& pos);
	void Update(sf::RenderWindow& window);

	const sf::Vector2f& GetPosition() const;
	const sf::Vector2f& GetCenterShape() const;
private:
	sf::Sprite m_circle;
	sf::Text m_text;
};