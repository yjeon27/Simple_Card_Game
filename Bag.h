#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include "MatchCard.h"
//#include "Queue.h"
using namespace std;

//	bag containing user-defined sets of cards randomly stored into array
//	randomly stored "cards" (elmeents) will be sent to Queue (DECK PILE) and stored as an array
class Bag {
private:
	int maxRank;
	MatchCard *all;
	MatchCard *diamond;
	MatchCard *heart;
	MatchCard *clubs;
	MatchCard *spades;

public:
	Bag() {}
	Bag(int);


	MatchCard* returnDeck() {
		return all;
	}


	MatchCard shuffle(int);


	~Bag() {
		//delete all, diamond, heart, clubs, spades;
	}
};

Bag::Bag(int maxRank) {

	cout << "Bag constructor has been called.\n\n";
	this->maxRank = maxRank;

	diamond = new MatchCard[maxRank];
	heart = new MatchCard[maxRank];
	clubs = new MatchCard[maxRank];
	spades = new MatchCard[maxRank];


	//	creating a bag of cards
	for (int i(1); i <= maxRank; i++) {
		diamond[i - 1] = MatchCard(i, "diamond");
		heart[i - 1] = MatchCard(i, "heart");
		clubs[i - 1] = MatchCard(i, "clubs");
		spades[i - 1] = MatchCard(i, "spades");
	}

	//	create an array that stores all cards of all suits in chronological order
	///	all[maxRank*4] = [ diamond[1], diamond[2], diamond[3]..., heart[maxRank], heart[maxRank+1], heart[maxRank+2]...]
	int k(0), j(0), l(0);
	all = new MatchCard[maxRank * 4];
	
	for (int i(0); i < maxRank * 4; i++) {
		if (i < maxRank) {
			all[i] = diamond[i];
		}
		else if (i >= maxRank && i < maxRank * 2) {
			all[i] = heart[k++];
		}
		else if (i >= maxRank * 2 && i < maxRank * 3) {
			all[i] = spades[j++];
		}
		else {
			all[i] = clubs[l++];
		}
	}

	cout << "PRINTING UNMIXED CARDS" << endl;
	cout << "_______________________" << endl;
	//	PRINT CARDS
	for (int i(0); i < maxRank * 4; i++) {
		cout << all[i] << endl;
	}


	//***********************DEBUGGING PURPOSES ONLY*********************
	///			WONT BE USING
	////	randomly mix cards (swap elements)
	//srand(time(NULL));
	//for (int i(0); i < 10; i++) {
	//	for (int i(0); i < maxRank * 4; i++) {
	//		int k = rand() % maxRank * 4;
	//		MatchCard temp = all[i];
	//		all[i] = all[k];
	//		all[k] = temp;
	//	}
	//}

	//cout << "\n\nPRINTING MIXED CARDS" << endl;
	//cout << "______________________" << endl;
	////	PRINT MIXED CARDS
	//for (int i(0); i < maxRank * 4; i++) {
	//	cout << all[i] << endl;
	//
	//}

	////	PRINT EXISTING CARDS
	//for (int i(0); i < maxRank; i++){

	//	cout << diamond[i] << endl;
	//	cout << heart[i] << endl;
	//	cout << clubs[i] << endl;
	//	cout << spades[i] << endl;
	//	cout << endl;

	//}

	cout << endl;
}


MatchCard Bag::shuffle(int i) {
	int k = rand() % (maxRank * 4 - i);

	MatchCard temp = all[k];
	all[k] = all[maxRank * 4 - i - 1];

	return temp;
}