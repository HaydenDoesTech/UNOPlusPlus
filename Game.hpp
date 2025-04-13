#pragma once
#define MAX_CARDS 108
#include <iostream>>
#include <string>
#include <SFML/Graphics.hpp>
#include <stack>

//sync, commit, pull request
class Game {

public:
	Game();
	~Game();
	void end_game();
	void start_game();
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
