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

using std::string;
using std::cin;
using std::cout;

//sync, commit, pull request
class Game {

public:
	Game();
	~Game();
	void end_game();
	void start_game();

	Card getDiscardPile()const
	{
		return discard_pile.top();
	}
private:
	std::stack<Card> discard_pile;
	sf::Color current_color;


};
void Game::end_game()
{
	std::cout << "Goodgame" << std::endl;
}
void Game::start_game()
{

}
