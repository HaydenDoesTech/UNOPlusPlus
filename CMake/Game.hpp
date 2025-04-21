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
#include <stack>
#include "Player.hpp"
#include "Card.hpp"

using std::string;
using std::cin;
using std::cout;

class Player;

//sync, commit, pull request
class Game {

public:
	Game();
	~Game();
	void end_game(sf::RenderWindow& window);
	void shuffle();
	void deal(Player p1, Player p2);
	void start_game();
	Card get_top_discard();
	Card get_top_draw();
	
private:
	Player user;
	Player p2;
	Card start_arr[108];
	std::stack<Card> discard_pile;
	std::stack<Card> draw_pile;
	sf::Color current_color;

	Card getDiscardPile()const
	{
		return discard_pile.top();
	}
};