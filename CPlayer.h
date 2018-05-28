#pragma once
#include<vector>
#include"Card.h"
using namespace std;

class CPlayer
{
public:
	CPlayer();
	~CPlayer();
public:
	Card Draw(Card);
	int BlackJackScore();
private:
	vector<Card> m_Hand;
};

