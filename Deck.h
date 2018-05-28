#pragma once
#include"Card.h"
#include<vector>
#include<algorithm>
#include <random>

using namespace std;

class Deck
{
public:
	Deck();
	~Deck();
public:
	void shuffle();
	Card Draw();
	void Insert(Card,int);
	int getNumOfCard() { return m_NumOfCard; }

private:
	vector<Card> m_deck;
	int m_NumOfCard;
};

