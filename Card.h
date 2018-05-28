#pragma once
#include<string>
using namespace std;

enum SUIT { SPADE, HEART, CLUB, DIAMOND };

class Card
{
public:
	Card();
	Card(SUIT suit, int num);
	~Card();
public:
	Card& operator =(const Card&);
	SUIT showSuit() const;
	string showSuitStr();
	int showNum() const;
private:
	SUIT m_suit;
	int m_num;
};

