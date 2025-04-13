/*******************************************************************************
 * Programmers: Hayden LaCelle, John Pierce, Ryan Gould                        *
 * Class: CPT_S 122; Lab Section 12L                                           *
 * Programming Assignment: PA #9 - Graphical Game: UNO in C++!                 *
 * Last Updated: 4/11/2025                                                     *
 *                                                                             *
 * Description: This programming assignment requires the development of a      *
 *              graphical application. For this, we have chosen to make a      *
 *              game -- and why not something with a good variety of colors,   *
 *              text, some shapes, and of course, some good-old board game fun *
 *              virtualized? Welcome to UNO in C++!                            *
 *                                                                             *
 * GitHub Repository: https://github.com/HaydenDoesTech/UNOPlusPlus            *
 *                                                                             *
 * File Description: Card.hpp serves as the definition file for the UNO cards. *
 *                                                                             *
 * Development KanBan Board: https://github.com/users/HaydenDoesTech/projects/ *
 *                           1                                                 *
 ******************************************************************************/

#pragma once // Guard code

#include "Game.hpp"

class Card : public sf::RectangleShape
{
public:
	// Constructor | Size = (20, 20)?
	Card(const sf::Color& color, const char symbol, const int power) : sf::RectangleShape()
	{
		this->setFillColor(color);
		this->symbol = symbol;
		this->power = power;
		this->setSize(sf::Vector2f(20, 20));
	}

	// Getters for the class
	char getSymbol() const
	{
		return this->symbol;
	}
	sf::Color getColor() const
	{
		return this->color;
	}
	int getPower() const
	{
		return this->power;
	}
private:
	char symbol; // Symbol of the card, such as 1, 2, 3, reverse
	sf::Color color; // Color of the card
	int power; // Type of card (gives it different powers) -- identifies what it is
};