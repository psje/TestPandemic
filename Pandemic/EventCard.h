#pragma once
#include<iostream>
class EventCard
{
private:
	int m_cardId;
public:
	
	EventCard(int cardId) :
		m_cardId(m_cardId)
	{}
	int GetId() {
		return m_cardId;
	}
};

