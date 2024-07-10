/*
Name: James Joyner
Date:
CS2 at UCA with Baarsch
*/


#include <iostream>
using namespace std;

struct Suit {
	string name;
	int value;
};

struct Rank {
	string name;
	int value;
};

struct Card {
	Suit suit;
	Rank rank;
	bool isFaceUp;
};

int main()
{
	srand(time(0));
	Suit suits[4] = {
		{"hearts", 4},
		{"diamonds", 3},
		{"clubs", 2},
		{"spades",1}
	};

	Rank ranks[13] = {
		{"Ace", 1},
		{"Two",2},
		{"Three",3},
		{"Four",4},
		{"Five",5},
		{"Six",6},
		{"Seven",7},
		{"Eight",8},
		{"Nine",9},
		{"Ten",10},
		{"Jack",10},
		{"Queen",10},
		{"King",10}
	};

	Card deck[52];

	for (int i = 0; i < 52; i++) {
		Card tempCard = { suits[i / 13], ranks[i % 13], true };
		deck[i] = tempCard;
	}

	//for (Card card:deck){
	//	cout << "The " << card.rank.name << " of " << card.suit.name << endl;




	for (int i = 0; i < 5; i++) {
		Card card = deck[rand() % 52];
		cout << "The " << card.rank.name << " of " << card.suit.name << endl;
	}
}



