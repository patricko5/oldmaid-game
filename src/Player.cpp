#include <string>
#include <list>
#include <iostream>
#include <map>
#include <vector>

#include "Card.h"
#include "Player.h"

Player::~Player() {
    for (Card* card : hand) {
        delete card;
    }
}

void Player::addCard(Card* c) {
    hand.push_back(c);
}

Card* Player::getCard(unsigned int index) {
    if (index >= hand.size()) {
        std::cerr << "Error: Card index out of bounds." << std::endl;
        // Handle the error - index out of bounds.
        return nullptr;
    }

    auto it = hand.begin();
    std::advance(it, index);
    Card* card = *it;
    hand.erase(it); // Remove the card from the hand
    return card; // Return the removed card
}

std::list<Card*>* Player::getHand() {
    return &hand;
}

void Player::checkAndRemovePairs() {
    std::map<Card::Rank, std::vector<Card*>> rankMap;

    // Group cards by rank
    for (Card* card : hand) {
        rankMap[card->rank].push_back(card);
    }

    // Iterate through the map and remove pairs
    for (auto& pair : rankMap) {
        auto& cards = pair.second;
        while (cards.size() >= 2) {
            // Instead of storing the card pointer, store a string identifier
            std::string cardIdentifier = cards[0]->toString() + " & " + cards[1]->toString();
            collectedPairs.push_back(cardIdentifier);

            // Delete and remove the cards from hand
            delete cards[0];
            delete cards[1];
            hand.remove(cards[0]);
            hand.remove(cards[1]);

            // Erase from vector
            cards.erase(cards.begin(), cards.begin() + 2);
        }
    }
}
void Player::displayCollectedPairs() const {
    if (collectedPairs.empty()) {
        std::cout << name << " has no pairs collected yet." << std::endl;
        return;
    }

    std::cout << name << "'s pairs: ";
    for (auto it = collectedPairs.begin(); it != collectedPairs.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != collectedPairs.end()) {
            std::cout << ", "; 
        }
    }
    std::cout << std::endl; 
}
