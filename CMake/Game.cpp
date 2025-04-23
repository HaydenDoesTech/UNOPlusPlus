#include "Game.hpp"

#include <random>

Game::Game()
{
    user = Player(7);
    p2 = Player(7);
}

Game::~Game()
{

}

void Game::end_game(sf::RenderWindow &window)
{
    std::cout << "Goodgame" << std::endl;
    window.close();
}

void Game::shuffle()
{

    std::random_device temp;
    std::mt19937 g(temp()); // this is a number generator
    std::shuffle(start_arr, start_arr + MAX_CARDS, g); // shuffles the deck
}
void Game::start_game()
{
    // // Initiallizing Draw Pile
    draw_pile = std::stack<Card>(); // Empty Pile

    std::vector<string> colors = {"Red", "Green", "Blue", "Yellow"};
    std::vector<string> values = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    // Add color cards
    for (const auto& color : colors) {
    // One zero for each color
    draw_pile.push(Card(color, "0", 1));

    // 1-9 Number Cards, Two each number
    for (size_t i = 1; i < values.size(); i++) {
    draw_pile.push(Card(color, values[i], 1));
    draw_pile.push(Card(color, values[i], 1));
    }
    }

    // Wild Cards
    for (int i = 0; i < 4; i++) {
    draw_pile.push(Card("Black", "Wild", 2));
    draw_pile.push(Card("Black", "Draw_Four", 2));
    }


    shuffle();
    deal(user, p2);

}



Card Game::get_top_discard()
{
    return this->discard_pile.top();
}

Card Game::get_top_draw()
{
    return this->draw_pile.top();
}

void Game::discard(const Card &card) {
    discard_pile.push(card);
}

void Game::setCurrentColor(sf::Color color) {
    current_color = color;
}

bool Game::drawEmpty() const {
    return draw_pile.empty();
}

Card Game::draw() {
    if (!draw_pile.empty()) {
        Card topCard = draw_pile.top(); // top card of draw pile
        draw_pile.pop(); // removes from top of draw pile
        return topCard; // returns the top card
    }
    else {
        shuffle(); // if the deck is empty, shuffle cards
    }
}

sf::Color Game::stringToColor(const string &colorName) {
    if (colorName == "Red") return sf::Color::Red;
    else if (colorName == "Green") return sf::Color::Green;
    else if (colorName == "Blue") return sf::Color::Blue;
    else if (colorName == "Yellow") return sf::Color::Yellow;
    else return sf::Color::White; // Wild
}

void Game::deal(Player p1, Player p2)
{

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
