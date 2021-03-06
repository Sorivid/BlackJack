// BlackJack.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Card.h"
#include"Deck.h"
#include"CPlayer.h"
#include<iostream>

using namespace std;


int main()
{
	Deck deck;
	deck.shuffle();

	CPlayer dealer, player;

	cout << "あなたが引いたカード" << endl;
	Card c = player.Draw(deck.Draw());
	cout << "1枚目:" << c.showSuitStr() << "の" << c.showNum() << endl;
	c = player.Draw(deck.Draw());
	cout << "2枚目:" << c.showSuitStr() << "の" << c.showNum() << endl;
	
	int scorePlayer = player.BlackJackScore();
	cout << "あなたのスコアは"<< scorePlayer << "です。" << endl;
	cout << endl;

	cout << "ディーラーが引いたカード" << endl;
	c = dealer.Draw(deck.Draw());
	cout << "1枚目:" << c.showSuitStr() << "の" << c.showNum() << endl;
	
	
	Card hiddenCard = dealer.Draw(deck.Draw());
	cout << "2枚目は分かりません" << endl;

	int scoreDealer = dealer.BlackJackScore();

	cout << "あなたのターンです。" << endl << endl;
	while (1)
	{
		cout << "カードを引きますか？ Y/N" << endl;
		string ans;
		cin >> ans;
		if (ans == "y" || ans == "Y")
		{
			Card tmp = player.Draw(deck.Draw());
			cout << "あなたは" << tmp.showSuitStr() << "の" << tmp.showNum() << "を引きました。" << endl;
			scorePlayer = player.BlackJackScore();
		}
		else if (ans == "n" || ans == "N")
		{
			break;
		}
		else
		{
			continue;
		}

		cout << "現在のスコアは" << scorePlayer << "です。" << endl;

		if (scorePlayer > 21)
		{
			cout << "GameOver" << endl;
			return 0;
		}
	}

	cout << "ディーラーのターンです。" << endl;
	while (1)
	{
		if (scoreDealer < 17)
		{
			cout << "カードを1枚引きます。" << endl;
			Card c = dealer.Draw(deck.Draw());
			cout << "引いたカードは" << c.showSuitStr() << "の" << c.showNum() << "です。" << endl;
			scoreDealer = dealer.BlackJackScore();
		}
		else
		{
			break;
		}
	}

	cout << "スコアを比較します" << endl;
	cout << "あなたのスコア　　：" << scorePlayer << endl;
	cout << "ディーラーのスコア：" << scoreDealer << endl;
	cout << "隠されたカードは" << hiddenCard.showSuitStr() << "の" << hiddenCard.showNum() << "でした。" << endl;

	if (scoreDealer > 21 || scorePlayer > scoreDealer)
	{
		cout << "YOU WIN" << endl;
	}
	else if (scoreDealer == scorePlayer) cout << "DRAW" << endl;
	else
	{
		cout << "YOU LOSE" << endl;
	}

	return 0;
}

