#include "Deck.h"
#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine
#include <chrono>    // For std::chrono::system_clock

Deck::~Deck() {
    // Cleanup any dynamically allocated Card objects
    for (auto& card : deck) {
        delete card;
    }
}

void Deck::shuffle() {
    // Use a random number generator to shuffle the deck
    auto rng = std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(deck.begin(), deck.end(), rng);
}

void Deck::addCard(Card* card) {
    deck.push_back(card);
}

Card* Deck::getCard() {
    if (!deck.empty()) {
        Card* topCard = deck.back();
        deck.pop_back();
        return topCard;
    }
    std::cerr << "Attempted to draw a card from an empty deck!" << std::endl;
    return nullptr; // Return nullptr if deck is empty
}

unsigned int Deck::size() {
    return deck.size();
}


void Deck::create() {
    deck.clear(); // Clear existing deck
    
    // Create a standard deck: 51 cards, all but one Queen
    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {

            // Create a new Card with the correct suit and rank
            deck.push_back(new Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank)));
        }
    }
}

void Deck::clearDeck() {
    for (Card* card : deck) {
        delete card;  // Assuming cards are dynamically allocated
    }
    deck.clear();
}