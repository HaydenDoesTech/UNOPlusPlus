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

const std::vector<Card>& Player::getHand() const
{
	return hand;
}

bool Player::playableCard(const Card& card) const
{
	for (std::vector<Card>::const_iterator A = hand.begin(); A != hand.end(); A++)
	{
		if (A->match(card)) return true;
	}
	return false;
}

void Player::drawHand(sf::RenderWindow& window)
{
	for (size_t i = 0; i < hand.size(); i++) {
		// Puts cards on Screen
		hand[i].setPosition(sf::Vector2f(100+ static_cast<float>(i) * 90, 100.f));
		window.draw(hand[i]); // draws card on screen
	}
}

void Player::showHand(sf::RenderWindow& window, float y)
{
	for (size_t i = 0; i < hand.size(); i++)
	{
		hand[i].setPosition(sf::Vector2f(100 + static_cast<float>(i) * 90, y));
		window.draw(hand[i]); // Draw the card on the window at y position
	}
}

int Player::selectCard(const Card& card, sf::Vector2i mousePosition)
{
	// Casting the mousePosition to float
	sf::Vector2f mousePos(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

	for (size_t i = 0; i < hand.size(); i++)
	{
		if (hand[i].getShape().getGlobalBounds().contains(mousePos))
		{
			if (hand[i].match(card))
			{
				return static_cast<int>(i);
			}
		}
	}
	return -1; // if no card was selected or the card didn't match
}

bool Player::playableActionCard(const Card& selectedCard, const Card& card)
{
	return selectedCard.match(card);
}

int Player::playerControls(const Card& card, sf::Vector2i mousePosition)
{
	return selectCard(card, mousePosition);
}

void Player::addCard(const Card &card) {
	hand.push_back(card); // Add card to Player Hand
	numCards++; // Add number of cards of Player hand
}

void Player::removeCard(int index) {
	if (index >= 0 && index < static_cast<int>(hand.size())) {
		hand.erase(hand.begin() + index);
		numCards--;
	}
}
