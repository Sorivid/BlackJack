#include "stdafx.h"
#include "Deck.h"


Deck::Deck()
{
	m_deck.resize(52);
	m_deck.erase(m_deck.begin(), m_deck.end());
	for (int i = 1; i <= 13; i++)
	{
		m_deck.push_back(Card(SPADE, i));
		m_deck.push_back(Card(HEART, i));
		m_deck.push_back(Card(DIAMOND, i));
		m_deck.push_back(Card(CLUB, i));
	}
	m_NumOfCard = 52;
}


Deck::~Deck()
{
	
}

void Deck::shuffle() 
{
	random_device seed_gen;
	mt19937 engine(seed_gen());
	std::shuffle(m_deck.begin(), m_deck.end(), engine);
}

Card Deck::Draw()
{
	Card card = m_deck[m_deck.size()-1];
	m_deck.pop_back();

	m_NumOfCard--;
	
	return card;
}

void Deck::Insert(Card card, int index)
{
	m_deck.insert(m_deck.begin() + index, card);
	m_NumOfCard++;
}