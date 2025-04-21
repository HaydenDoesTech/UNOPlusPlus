#include "Game.hpp"

#include <random>

Game::Game()
{
    user = Player(7);
    p2 = Player(7);
}

Game::~Game()
{
    ;
}

void Game::end_game(sf::RenderWindow &window)
{
    std::cout << "Goodgame" << std::endl;
    window.close();
}

void Game::shuffle()
{
    // srand(time(NULL));
    // int temp = 0;
    // Card temp2;
    // int shuffles = 0;
    // while (shuffles != 50)
    // {
    //     temp = rand() % 108 + 1;
    //     temp2 = start_arr[temp];
    //     start_arr[shuffles] = temp2;
    //     start_arr[temp] = start_arr[shuffles];
    //     shuffles++;
    // }
    // NEEDS COMPLETION? while ();

    std::random_device temp;
    std::mt19937 g(temp()); // this is a number generator
    std::shuffle(start_arr, start_arr + 109, g); // shuffles the deck
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

void Game::deal(Player p1, Player p2)
{
    // int pos = 0;
    //
    // // Deals 7 cards to Each Player
    // //for(int i = 0; i < 7; i++)
    // //{
    // //p1.addCard(start_arr[i++]);
    // //p2.addCard(start_arr[i++]);
    // //}
    // //No "addCard" exists -- this should be implemented in the drawCard function in Player
    //
    // // Rest of Cards go to Draw Pile
    // while(pos < 7)
    // {
    //     draw_pile.push(start_arr[pos++]);
    // }
    //
    // // Starts discard Pile with Backwards card
    // if(!draw_pile.empty())
    // {
    //     discard_pile.push(draw_pile.top());
    //     draw_pile.pop();
    // }

    int pos = 0;
    // deal 7 cards to each person
    for (int i = 0; i < 7; i++) {
        p1.addCard(start_arr[pos++]);
        p2.addCard(start_arr[pos++]);
    }

    // Puts the rest of the cards into draw pile
    while (pos < 108) {
        draw_pile.push(start_arr[pos++]);
    }

    // Places top card from draw to discard
    if (!draw_pile.empty()) {
        discard_pile.push(draw_pile.top());
        draw_pile.pop();
    }
}