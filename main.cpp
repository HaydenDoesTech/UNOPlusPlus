/*******************************************************************************
 * Programmers: Hayden LaCelle, John Pierce, Ryan Gould                        *
 * Class: CPT_S 122; Lab Section 12L                                           *
 * Programming Assignment: PA #9 - Graphical Game: UNO in C++!                 *
 * Last Updated: 4/11/2025                                                     *
 *                                                                             *
 * Description: This programming assignment requires the development of a      *
 *              graphical application. For this, we have chosen to make a      *
 *              game -- and why not something with a good variety of colors,   *
 *              text, some shapes, and of course, some good-old board game fun *
 *              virtualized? Welcome to UNO in C++!                            *
 *                                                                             *
 * GitHub Repository: https://github.com/HaydenDoesTech/UNOPlusPlus            *
 *                                                                             *
 * File Description: main.cpp serves as the central component and operator of  *
 *                   the program.                                              *
 *                                                                             *
 * Development KanBan Board: https://github.com/users/HaydenDoesTech/projects/ *
 *                           1                                                 *
 ******************************************************************************/

#include "Player.hpp"

// Individual elements of the game

int main(void)
{
	// To-Do Items Located on Development KanBan Board

	sf::RenderWindow window;
	window.create(sf::VideoMode({ 800, 600 }), "Game Window");

	// Draw Pile
	sf::RectangleShape back(sf::Vector2f(20, 60), sf::Vector2f(0.0, 0.0));
	

	while (window.isOpen())
	{
		
		// Check all the window's events that were triggered since the last iteration of the loop
		while (const std::optional event = window.pollEvent())
		{
			// "Close Requested" event: we close the window
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		window.clear(sf::Color::White);
		window.display();
	}

	return 0; // Code 0 indicates the program ran successfully.
}