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

#include <SFML/Graphics.hpp> // SFML Framework for Graphics
#include <iostream>



class Card : public sf::RectangleShape
{
public:
	// Constructor | Size = (20, 20)?
	Card(const std::string& color, const std::string symbol, const int power) : color(color), symbol(symbol), power(power)
	{
		// this->symbol = symbol;
		// this->power = power;
		// loadTexture();
	std::string fPath = "cards/" + color + "_" + symbol + ".png";
	texture.loadFromFile(fPath);

		if (!texture.loadFromFile("cards/" + color + "_" + symbol + ".png")) {
			std::cout << "Failed to load card texture" << '\n';
		}
		sprite.setTexture(texture);
	}
	Card() {}

	// Getters for the class
	std::string getSymbol() const
	{
		return this->symbol;
	}
	std::string getColor() const
	{
		return this->color;
	}
	int getPower() const
	{
		return this->power;
	}

	// Member Functions

	// Checks if this card can be played on top of another card
	bool match(const Card& other) const
	{
		return color == other.color || symbol == other.symbol;
	}

	// NEED TO FINSIH THIS
	void loadTexture() {
		std::string fStream = "cards/" + color + "_" + symbol + ".png";
		if (texture.loadFromFile(fStream)) {
			sprite.setTexture(texture);
			sprite.setScale(.5f, .5f); // adjust as needed
		}
		else {
			std::cout << "ERROR loading texture" << '\n';
		}
	}

	void setCardPosition(float x, float y) {
		sprite.setPosition(x, y);
	}

	void drawCardTexture(sf::RenderWindow& window) {
		window.draw(sprite);
	}

private:
	std::string symbol; // Symbol of the card, such as 1, 2, 3, reverse
	std::string color; // Color of the card
	int power; // Type of card (gives it different powers) -- identifies what it is
	sf::Sprite sprite;
	sf::Texture texture;
};