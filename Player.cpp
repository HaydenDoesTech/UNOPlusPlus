/*
	Author: John Pierce
	Date: 4/12/2025
	Description: This programming assignment requires the development of a graphical application. For this, we have chosen to make a game -- and why not something with a good variety of colors, text, some shapes, and of course, some good-old board game fun virtualized? Welcome to UNO in C++!
	Assignment: Programing Assignment 9: The Game of Uno
	GitHub Repository: https://github.com/HaydenDoesTech/UNOPlusPlus
	Development KanBan Board: https://github.com/users/HaydenDoesTech/projects/
	File Description: Person.cpp serves as the base definition for all player classes
*/


#include "Player.hpp"

Player::Player(int newNumCards)
{
	this->numCards = newNumCards;
}

int Player::getNumCards() const
{
	return this->numCards;
}

bool Player::playableCard()
{
	if(discard_pile.peak == )
	return false;
}

Player::Player(int newNumCards)
{
	this->numCards = newNumCards;
}
