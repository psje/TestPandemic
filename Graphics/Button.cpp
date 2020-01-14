#include "Button.h"

#include<iostream>

Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& text,
	const sf::Font& font, 
	const sf::Color& idleColor, 
	const float thicknes,
	const sf::Color& thicknesColor)
{
	m_buttonState = ButtonStates::BTN_IDLE;

	m_shape.setPosition(position);
	m_shape.setSize(size);
	m_shape.setOutlineThickness(thicknes);
	m_shape.setOutlineColor(thicknesColor);
	m_shape.setFillColor(idleColor);

	m_font = font;

	m_text.setFont(m_font);
	m_text.setString(text);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(15);
	m_text.setPosition(position);

	m_idleColor = idleColor;
}

void Button::Rend(sf::RenderTarget& target) const
{
	target.draw(m_shape);
	target.draw(m_text);
}

void Button::UpdateState(sf::RenderWindow& window)
{
	if (IsMouseOnButton(window))
		m_text.setColor(sf::Color::Yellow);

	else m_text.setColor(sf::Color::White);
}

void Button::UpdatePosition(const sf::Vector2f& position)
{
	m_shape.setPosition(position);

	sf::Vector2f positionText;
	positionText.x = m_shape.getPosition().x+m_shape.getSize().x/2 - (m_text.getCharacterSize() * m_text.getString().getSize()/2)+40;
	positionText.y = position.y + m_text.getCharacterSize()/2;

	m_text.setPosition(positionText);
}

bool Button::IsPressed() const
{
	if (m_text.getFillColor()==sf::Color::Yellow && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return true;

	return false;
}

bool Button::IsMouseOnButton(sf::RenderWindow& window) const
{
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));

	//m_shape.setPosition(mousePos.x-5,mousePos.y-25);

	return mousePos.x - 3 >= m_shape.getPosition().x && mousePos.x - 3 <= m_shape.getPosition().x + m_shape.getSize().x &&
		mousePos.y - 23 >= m_shape.getPosition().y && mousePos.y - 23 <= m_shape.getPosition().y + m_shape.getSize().y;
		
}

const sf::Vector2f& Button::GetShapeSize() const
{
	return m_shape.getSize();
}

const sf::Vector2f& Button::GetPosition() const
{
	return m_shape.getPosition();
}

const sf::Vector2f& Button::GetPositionText() const
{
	return m_text.getPosition();
}
