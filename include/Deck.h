#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
 public:
    virtual ~Deck();

    /**
    * Shuffle the deck of cards.
    */
    virtual void shuffle();

    /**
    * Add a card to the deck of cards.
    * @param card Card added to deck.
    */
    virtual void addCard(Card* card);

    /**
    * Get the top card from the deck of cards.
    * @return Card on top of deck.
    */
    virtual Card* getCard();

    /**
    * Size of the deck of cards.
    * @return The size of the deck of cards.
    */
    virtual unsigned int size();

    /**
    * Create a standard deck of cards with thirteen cards (Ace to King)
    * for each of four suits (Spade, Club, Heart, Diamond).
    */
    virtual void create();

    virtual void clearDeck();

 protected:
     /**
     * The collection of cards that form the deck.
     */
    std::vector<Card*> deck;
};

#endif // DECK_H
