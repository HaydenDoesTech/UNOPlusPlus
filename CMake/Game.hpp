#pragma once
#define MAX_CARDS 108
#include <SFML/Graphics.hpp> // SFML Framework for Graphics
#include <SFML/Window.hpp> // SFML Framework for Window
#include <SFML/System.hpp> // SFML Framework for system
#include <iostream> // Input Output Commands
#include <string> // String Commands
#include <fstream> // Stream Commands
#include <vector> // Vector Commands
#include <cctype>
#include <algorithm>
#include <span> // Span Commands
#include <ctime>
#include <cstdlib>
#include <stack>
#include "Player.hpp"
#include "Card.hpp"

using std::string;
using std::cin;
using std::cout;

class Player; // Forward declaration, found on: https://www.geeksforgeeks.org/what-are-forward-declarations-in-c/

//sync, commit, pull request
class Game {

public:
	Game();
	~Game();
	void end_game(sf::RenderWindow& window);
	static void shuffle(std::vector<Card>& deck);
	void deal(Player& p1, Player& p2, std::stack<Card>& drawP, std::stack<Card>& discardP);
	void start_game();
	Card get_top_discard();
	Card get_top_draw();

	// Discards a Card
	void discard(const Card& card);

	// Sets the Current Color, needed for Wild Cards
	void setCurrentColor(sf::Color color);

	// Returns if the Draw Pile is Empty
	bool drawEmpty() const;

	// Draws a card from Draw Pile, Returns Top Card of Draw Pile
	Card draw();

	// Converts a string to sf::color
	sf::Color stringToColor(const string& colorName);
	
private:
	Player user;
	Player p2;
	Card startDeck[108];
	std::stack<Card> discard_pile;
	std::stack<Card> draw_pile;
	sf::Color current_color;

	Card getDiscardPile()const
	{
		return discard_pile.top();
	}
};