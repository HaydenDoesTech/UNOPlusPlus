#pragma once
#define MAX_CARDS 108
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <stack>
#include "Card.hpp"
#include "Player.hpp"
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
