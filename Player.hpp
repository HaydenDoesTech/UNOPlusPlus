/*
	Author: John Pierce
	Date: 4/12/2025
	Description: This is the Header file for the Player Class for the game of UNO! This will be the base class for other player classes!
*/

#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::cin;


class Player
{
public:
	// Constructor
	Player(int newNumCards = 0);

	// Getters
	int getNumCards()const;

	// Setters
	void setNumCards(int newNumCards);

private:
	Card handArr[108];
	int numCards;
};



#endif