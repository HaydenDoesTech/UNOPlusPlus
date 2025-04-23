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

void Game::shuffle(std::vector<Card>& deck)
{
    // int temp = 0;
    // Card temp2;
    // int shuffles = 0;
    // while (shuffles != 107) {
    //     temp = rand() % MAX_CARDS;
    //     temp2 = startDeck[temp];
    //     std::swap(startDeck[shuffles], startDeck[temp]);
    //     shuffles++;
    // }
    // // push shuffled cards to stack
    //     for (int i = 0; i < MAX_CARDS; i++) {
    //         draw_pile.push(startDeck[i]);
    //     }
   for (std::size_t i = deck.size(); i > 1; i--) {
       std::size_t j = (rand() % i-1);
       std::swap(deck[i - 1], deck[j]);
   }
}



void Game::start_game()
{
    // // // Initiallizing Draw Pile
    // draw_pile = std::stack<Card>(); // Empty Pile
    //
    // std::vector<string> colors = {"Red", "Green", "Blue", "Yellow"};
    // std::vector<string> values = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    //
    // // Add color cards
    // for (const auto& color : colors) {
    // // One zero for each color
    // draw_pile.push(Card(color, "0", 1));
    //
    // // 1-9 Number Cards, Two each number
    // for (size_t i = 1; i < values.size(); i++) {
    // draw_pile.push(Card(color, values[i], 1));
    // draw_pile.push(Card(color, values[i], 1));
    // }
    // }
    //
    // // Wild Cards
    // for (int i = 0; i < 4; i++) {
    // draw_pile.push(Card("Black", "Wild", 2));
    // draw_pile.push(Card("Black", "Draw_Four", 2));
    // }
    //
    //
    // shuffle();
    // deal(user, p2, draw_pile, discard_pile);
    std::vector<Card> fullD;
    const std::vector<string> colors = {"Red", "Green", "Blue", "Yellow"};
    const std::vector<string> values = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    for (std::size_t i = 0; i < colors.size(); i++) {
        const string& c = colors[i];
        fullD.emplace_back(c, "0", 1);

        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < 2; k++) {
                fullD.emplace_back(c, std::to_string(j) , 1);
            }
        }
    }
}



Card Game::get_top_discard()
{
    return this->discard_pile[0];
}

Card Game::get_top_draw()
{
    return this->draw_pile[0];
}

std::vector<Card> Game::getDrawPile() {
    return this->draw_pile;
}

std::vector<Card> Game::getDiscardPile()
{
    return this->discard_pile;
}

void Game::discard(const Card &card) {
    discard_pile.emplace_back(card);
}

void Game::setCurrentColor(sf::Color color) {
    current_color = color;
}

bool Game::drawEmpty() const {
    return draw_pile.empty();
}

Card Game::draw() {
    if (!draw_pile.empty()) {
        Card topCard = draw_pile[0]; // top card of draw pile
        draw_pile.erase(draw_pile.begin());// removes from top of draw pile

        return topCard; // returns the top card
    }
    else {
        shuffle(draw_pile);
        return draw();
    }
}

sf::Color Game::stringToColor(const string &colorName) {
    if (colorName == "Red") return sf::Color::Red;
    else if (colorName == "Green") return sf::Color::Green;
    else if (colorName == "Blue") return sf::Color::Blue;
    else if (colorName == "Yellow") return sf::Color::Yellow;
    else return sf::Color::White; // Wild
}

void Game::deal(Player& p1, Player& p2, std::stack<Card>& drawP, std::stack<Card>& discardP)
{
    std::vector<Card> fullDeck; // put all cards in here
    std::vector<string> colors = {"Red", "Green", "Blue", "Yellow"};

    // loop for number cards
    for (const string& color : colors) {
        fullDeck.emplace_back(color, "0", 1); // emplace_back is equivalent to push_back
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= 9; j++) {
                fullDeck.emplace_back(color, std::to_string(j), 1);
            }
        }
    }

    // wild and wild draw four
    for (int i = 0; i < 4; i++) {
        fullDeck.emplace_back("Black", "Wild", 2);
        fullDeck.emplace_back("Black", "Draw_Four", 2);
    }


    shuffle(fullDeck);
    std::cout << "Index: " << rand() % fullDeck.size() << '\n';

    // deal 7 cards to each player
    for (int i = 0; i < 7; i++) {
        p1.addCard(fullDeck.back());
        fullDeck.pop_back();
        p2.addCard(fullDeck.back());
        fullDeck.pop_back();
    }

    // puts top card to discard pile
    discardP.push(fullDeck.back());
    fullDeck.pop_back();

    // loops to put rest of cards into draw pile
    while (!fullDeck.empty()) {
        drawP.push(fullDeck.back());
        fullDeck.pop_back();
    }
}
