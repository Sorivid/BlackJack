#include "stdafx.h"
#include "Card.h"


Card::Card()
{
	m_suit = SPADE;
	m_num = 2;
}

Card::Card(SUIT suit, int num):m_suit(suit),m_num(num)
{
}

Card::~Card()
{
}

SUIT Card::showSuit() const
{
	return m_suit;
}

Card& Card::operator =(const Card& card) // const ‚ğ•t‚¯‚È‚¢‚Æ@= Card‚Æ‚Å‚«‚È‚¢ˆÓ–¡‚ª‚í‚©‚ç‚È‚¢B
{
	m_num = card.showNum();
	m_suit = card.showSuit();
	return *this;
}

string Card::showSuitStr() 
{
	switch (m_suit)
	{
	case SPADE:
		return "SPADE";
		break;
	case CLUB:
		return "CLUB";
		break;
	case HEART:
		return "HEART";
		break;
	case DIAMOND:
		return "DIAMOND";
		break;
	default:
		return "NONE";
	}
}

int Card::showNum() const
{
	return m_num;
}