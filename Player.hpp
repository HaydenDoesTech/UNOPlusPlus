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


// Base player class
class Player : public Card
{
public:
	/* Constructor */
	Player(int newNumCards = 0);

	/* Getter */
	int getNumCards()const;

	/* Setter */
	void setNumCards(int newNumCards);

	/* Member Functions */

	// Checks if there is any playable cards in hand based on top discard card
	bool playableCard(const Card& card)const;

	// Pure virtual funciton to draw the player's hand
	virtual void drawHand(sf::RenderWindow& window) = 0;

	// Displays the hand on the screen at the given (x,y) position
	void showHand(sf::RenderWindow& window, float y);

	// Returns the index of the card clicked on by player
	int selectCard(const Card& card, sf::Vector2i mousePosition);

	// Checks if the action card can be played on top of another action card
	bool playableActionCard(const Card& selectedCard, const Card& card);

	// User Controls Function
	virtual int playerControls(const Card& card, sf::Vector2i mousePosition);

private:
	std::vector<Card> hand; // Cards in Hand
	int numCards; // Number of Cards in Hand
};