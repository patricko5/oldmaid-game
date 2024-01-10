#include "OldMaidDeck.h"
#include <algorithm> // For std::shuffle
#include <random>    // For random number generation
#include <chrono>    // For std::chrono::system_clock
#include <vector>    // For std::vector

void OldMaidDeck::create() {
    // Create a standard deck
    Deck::create();

    // Find all Queens
    std::vector<Card*> queens;
    for (Card* card : deck) {
        if (card->rank == Card::QUEEN) {
            queens.push_back(card);
        }
    }

    // Randomly remove one Queen
    if (!queens.empty()) {
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::uniform_int_distribution<int> distribution(0, queens.size() - 1);
        int randomIndex = distribution(generator);

        Card* queenToRemove = queens[randomIndex];
        auto it = std::find(deck.begin(), deck.end(), queenToRemove);
        if (it != deck.end()) {
            delete *it; 
            deck.erase(it); 
        }
    }
}