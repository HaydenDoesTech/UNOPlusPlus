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

bool Player::playableCard(const Card& card) const
{
	for (std::vector<Card>::const_iterator A = hand.begin(); A != hand.end(); A++)
	{
		if (A->match(card)) return true;
	}
	return false;
}

void Player::showHand(sf::RenderWindow& window, float y)
{
	for (size_t i = 0; i < hand.size(); i++)
	{
		hand[i].setPosition(100 + i * 90, y);
		hand[i].draw(window);
	}
}

int Player::selectCard(const Card& card, sf::Vector2i mousePosition)
{
	for (size_t i = 0; i < hand.size(); i++)
	{
		if (hand[i].getShape().getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			if (hand[i].match(card))
			{
				return static_cast<int>(i);
			}
		}
	}
}

bool Player::playableActionCard(const Card& selectedCard, const Card& card)
{
	return selectedCard.match(card);
}

int Player::playerControls(const Card& card, sf::Vector2i mousePosition)
{
	return selectCard(card, mousePosition);
}

Player::Player(int newNumCards)
{
	this->numCards = newNumCards;
}
