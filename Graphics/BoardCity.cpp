#include "BoardCity.h"

BoardCity::BoardCity(sf::Sprite& circle, sf::Text& text):m_circle(circle),m_text(text)
{
}

void BoardCity::Rend(sf::RenderTarget& target)
{
	target.draw(m_circle);
	target.draw(m_text);
}

void BoardCity::SetPosition(const sf::Vector2i& pos)
{
	m_circle.setPosition(pos.x,pos.y);

	int x = m_circle.getScale().y * m_circle.getTexture()->getSize().y;

	m_text.setPosition(pos.x,pos.y+x);
}

void BoardCity::Update(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition().x >= m_circle.getPosition().x && sf::Mouse::getPosition().x<=m_circle.getPosition().x+m_circle.getScale().x*m_circle.getTexture()->getSize().x &&
		sf::Mouse::getPosition().y >= m_circle.getPosition().y && sf::Mouse::getPosition().y<=m_circle.getPosition().y+m_circle.getScale().y*m_circle.getTexture()->getSize().y)   
		m_text.setColor(sf::Color::Yellow);
	else m_text.setColor(sf::Color::White);
}

const sf::Vector2f& BoardCity::GetPosition() const
{
	return m_circle.getPosition();
}

const sf::Vector2f& BoardCity::GetCenterShape() const
{
	return m_circle.getPosition();
}
