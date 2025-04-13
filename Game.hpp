#pragma once
#ifndef GAME
#define GAME
#include <iostream>>
#include <string>

class Game {

public:
	void end_game();
	void start_game();
private:

};
void Game::end_game()
{
	std::cout << "Goodgame" << std::endl;
}
void Game::start_game()
{

}

#endif