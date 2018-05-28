#include "stdafx.h"
#include "CPlayer.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

Card CPlayer::Draw(Card card)
{
	m_Hand.push_back(card);

	return card;
}

int CPlayer::BlackJackScore()
{
	int sum = 0;
	for (unsigned int i = 0; i < m_Hand.size(); i++)
	{
		int score = m_Hand[i].showNum();
		if (score > 10) score = 10;
		sum += score;
	}
	return sum;
}