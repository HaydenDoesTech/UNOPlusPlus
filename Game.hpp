#pragma once
#define MAX_CARDS 108
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <stack>
#include <Card.hpp>

//sync, commit, pull request
class Game {

public:
	Game();
	~Game();
	void end_game();
	void shuffle();
	void deal();
	void start_game();
private:
	std::stack<Card> discard_pile;
	std::stack<Card> draw_pile;
	sf::Color current_color;
	char current_card;


};
void Game::end_game()
{
	std::cout << "Goodgame" << std::endl;
	sf::RenderWindow::Window::close;
}
void Game::start_game()
{

}