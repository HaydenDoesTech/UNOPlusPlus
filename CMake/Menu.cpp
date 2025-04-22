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
 * File Description: Menu.cpp contains the functions declared in Menu.hpp.     *
 *                                                                             *
 * Development KanBan Board: https://github.com/users/HaydenDoesTech/projects/ *
 *                           1                                                 *
 ******************************************************************************/

#include "Menu.hpp" // Original header file

void Menu::displayMenu()
{
	// Used to render the window onto the computer screen
	sf::RenderWindow menuWindow;
	menuWindow.create(sf::VideoMode({ 800, 800 }), "Menu | UNO in C++");

	// Render the font used for the menu.
	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text button1;
	button1.setFont(font);
	button1.setString("[Start Game]");
	button1.setCharacterSize(20);
	button1.setFillColor(sf::Color::Red); // only temporarily red
	button1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	button1.setPosition(300.f, 70.f);

	sf::Text button2;
	button2.setFont(font);
	button2.setString("[Rules]");
	button2.setCharacterSize(20);
	button2.setFillColor(sf::Color::Red); // only temporarily red
	button2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	button2.setPosition(300.f, 100.f);

	sf::Text button3;
	button3.setFont(font);
	button3.setString("[Exit Game]");
	button3.setCharacterSize(20);
	button3.setFillColor(sf::Color::Red); // only temporarily red
	button3.setStyle(sf::Text::Bold | sf::Text::Underlined);
	button3.setPosition(300.f, 130.f);

	sf::Text footer1;
	footer1.setFont(font);
	footer1.setString("Created by Hayden LaCelle, John Pierce, Ryan Gould");
	footer1.setCharacterSize(15);
	footer1.setFillColor(sf::Color::Red); // only temporarily red
	footer1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	footer1.setPosition(10.f, 500.f);

	sf::Text footer2;
	footer2.setFont(font);
	footer2.setString("[GitHub Repository]      [Video Demonstration]");
	footer2.setCharacterSize(15);
	footer2.setFillColor(sf::Color::Red); // only temporarily red
	footer2.setStyle(sf::Text::Bold);
	footer2.setPosition(5.f, 550.f);

	// Draw everything onto the screen
	menuWindow.draw(button1);
	menuWindow.draw(button2);
	menuWindow.draw(button3);
	menuWindow.draw(footer1);
	menuWindow.draw(footer2);
	menuWindow.display();

	// What we should be printing out via this menu:
	/* --- Some sort of logo or text header --- 
	     
		           [Start Game]
				     [Rules]
				   [Exit Game]

	Created by Hayden LaCelle, John Pierce, Ryan Gould
	[GitHub Repository]          [Video Demonstration]*/

	/* switch (option)
	{
	case 1: // Start the game, call start game function for Game object?
		break;
	case 2: // Display the rules, insert these once we've gotten further into development
		break;
	case 3: // Exit game
		break;
	} */

	while (menuWindow.isOpen()) {
		sf::Event event{};
		while (menuWindow.pollEvent(event))
		{
			// Closes Window
			if(event.type == sf::Event::Closed) menuWindow.close();

			if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(menuWindow);

				// TODO: check for position, then start the game, display rules, or exit based on position
			}
		}
	}
}

void Menu::displayRules()
{
	// TO-DO
}