/*
	Author: John Pierce
	Date: 4/12/2025
	Description: This programming assignment requires the development of a graphical application. For this, we have chosen to make a game -- and why not something with a good variety of colors, text, some shapes, and of course, some good-old board game fun virtualized? Welcome to UNO in C++!
	Assignment: Programing Assignment 9: The Game of Uno
	GitHub Repository: https://github.com/HaydenDoesTech/UNOPlusPlus
	Development KanBan Board: https://github.com/users/HaydenDoesTech/projects/
	File Description: Person.hpp serves as the base definition for all player classes
*/

#pragma once

#include "Card.hpp"


class Player : public Card
{
public:
	// Constructor
	Player(int newNumCards = 0);

	// Getters
	int getNumCards()const;

	// Setters
	void setNumCards(int newNumCards);

	// Member Functions
	bool playableCard();


private:
	Card handArr[108];
	int numCards;
};