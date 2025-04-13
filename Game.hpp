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
#include "Card.hpp"
#include "Player.hpp"

using std::string;
using std::cin;
using std::cout;

//sync, commit, pull request
class Game {

public:
	Game();
	~Game();
	void end_game();
	void shuffle();
	void deal(Player p1, Player p2);
	void start_game();
	Card get_top_discard();
	Card get_top_draw();
	
private:
	Player user,
		p2;
	Card start_arr[108];
	std::stack<Card> discard_pile;
	std::stack<Card> draw_pile;
	

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
	sf::RenderWindow::Window::close;
}
void Game::shuffle()
{
	srand(time(NULL));
	int temp = 0;
	Card temp2;
	int shuffles = 0;
	while (shuffles != 50)
	{
		temp = rand() % 108 + 1;
		temp2 = start_arr[temp];
		start_arr[shuffles] = temp2;
		start_arr[temp] = start_arr[shuffles];
		shuffles++;
	}
	while ();
}
void Game::start_game()
{

}

Card Game::get_top_discard()
{
	return this->discard_pile.top();
}

Card Game::get_top_draw()
{
	return this->draw_pile.top();
}