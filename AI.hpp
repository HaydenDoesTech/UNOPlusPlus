/*
	Author: John Pierce
	Date: 4/13/2025
	Description: This programming assignment requires the development of a graphical application. For this, we have chosen to make a game -- and why not something with a good variety of colors, text, some shapes, and of course, some good-old board game fun virtualized? Welcome to UNO in C++!
	Assignment: Programing Assignment 9: The Game of Uno
	GitHub Repository: https://github.com/HaydenDoesTech/UNOPlusPlus
	Development KanBan Board: https://github.com/users/HaydenDoesTech/projects/
	File Description: AI.hpp serves as the base definition for the AI
*/

#pragma once

#include "Player.hpp"

class AI : public Player
{
public:

	/* Member Functions */

	// Draws the AI Hand as hidden at top of screen
	void drawHand(sf::RenderWindow& window) override
	{
		for (size_t i = 0; i < getHand().size(); i++)
		{
			sf::RectangleShape back(sf::Vector2f(80, 120));
			back.setFillColor(sf::Color(100, 100, 100));
			back.setPosition(sf::Vector2f(100 + static_cast<float>(i) * 90, 50));
			window.draw(back);
		}
	}

private:

};