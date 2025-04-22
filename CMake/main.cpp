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

#include "Game.hpp"
#include "Menu.hpp"

// Individual elements of the game

int main(void)
{
	// To-Do Items Located on Development KanBan Board

	// Game Window
	sf::RenderWindow window;
	window.create(sf::VideoMode({ 800, 600 }), "Game of UNOPlusPlus");
	window.setFramerateLimit(60);

	Game unoPlusPlus;

	Menu menu;
	menu.displayMenu();

	// Table Surface for Playing
	sf::RectangleShape table(sf::Vector2f(800.f, 600.f));
	table.setFillColor(sf::Color::White);

	// Players
	Player user(7);
	Player ai(7);

	unoPlusPlus.shuffle();
	unoPlusPlus.deal(user, ai);

	bool userTurn = true;
	bool gameOver = false;

	while (window.isOpen() && !gameOver)
	{
		sf::Event event{};
		while (window.pollEvent(event))
		{
			// Closes Window
			if(event.type == sf::Event::Closed) window.close();

			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			// User Card Selection
			int selectedCardIndex = user.selectCard(unoPlusPlus.get_top_discard(), mousePos);
			if (selectedCardIndex != -1) {
				// goes with the selected card
				Card selectedCard = user.getHand()[selectedCardIndex];
				// Plays the selected card
				unoPlusPlus.discard(selectedCard);
				user.removeCard(selectedCardIndex);

				// Check UNO Winning Conditions
				if (user.getHand().empty()) {
					std::cout << "Winner Winner Chicken Dinner!!\n";
					gameOver = true;
				}

				userTurn = false; // Ends User Turn
			}
				else {
					// If Card is an Invalid Input
					if (!unoPlusPlus.drawEmpty()) {
						Card drawnCard = unoPlusPlus.draw(); // draws from draw pile
						user.addCard(drawnCard); // adds the newly drawn card to player hand

					}
				}
			}
		}

		// AI Turn




		// White Playing Surface
		window.clear(sf::Color::White);

		// Draws Discard Pile in Center of Screen
		Card discardPile = unoPlusPlus.get_top_discard();
		discardPile.setPosition(sf::Vector2f(370, 250));
		window.draw(discardPile);

		// Draws Draw Pile in Center of Screen
		Card drawPile = unoPlusPlus.get_top_discard();
		drawPile.setPosition(sf::Vector2f(430, 250));
		window.draw(drawPile);

		// Draws Player Hand at bottom of screen
		// Y position a500
		user.showHand(window, 500.f);

		// Draws AI Hand at Top of Screen
		ai.drawHand(window);

		window.display();
	}

	return 0; // Code 0 indicates the program ran successfully.
}