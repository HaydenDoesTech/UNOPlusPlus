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

#pragma once // Guard code

#include <SFML/Graphics.hpp> // SFML Framework for Graphics
#include <iostream> // Input Output Commands
#include <string> // String Commands
#include <fstream> // Stream Commands
#include <vector> // Vector Commands
#include <cctype>
#include <algorithm>
#include <span> // Span Commands
#include <stack>
#include "Game.hpp"
#include "Menu.hpp" // Original header file

void Menu::displayMenu()
{
	// Used to render the window onto the computer screen
	sf::RenderWindow menuWindow(sf::VideoMode({ 800, 800 }), "Menu | UNO in C++");

	// Text/font SF functions are not working -- we will need to figure this out soon.

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
}

void Menu::displayRules()
{
	// TO-DO
}