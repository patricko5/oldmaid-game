#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
#include <string>

class Card { 
 public:
    /** Standard card suits */
    enum Suit {CLUB, DIAMOND, SPADE, HEART};

    /** Standard card ranks */
    enum Rank {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
               JACK, QUEEN, KING
              };

    /**
    * Create a card of suit s and rank r.
    * @param s Suit of the card.
    * @param r Rank of the card.
    */
    Card(Suit s, Rank r):suit(s), rank(r) {}

    /**
    * @return A text representation of the card's rank.
    */
    static std::string getRank(const Card::Rank rank);

    /**
    * @return A text representation of the card's suit.
    */
    static std::string getSuit(const Card::Suit suit);

    /**
    * Suit of the card.
    */
    const Suit suit;

    /**
    * Rank of the card.
    */
    const Rank rank;

    /**
    * Overloaded << operator that outputs a text representation of a Card.
    * @param os The output stream.
    * @param c The card to represent.
    */
    friend std::ostream& operator<<(std::ostream& os, const Card& c);
    std::string toString() const;
};

#endif // CARD_H_INCLUDED
