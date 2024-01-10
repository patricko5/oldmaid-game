#include "Card.h"


std::string Card::getRank(const Card::Rank rank) {
    static const std::string ranks[] = {"1", "2", "3", "4", "5", 
                                        "6", "7", "8", "9", "10",
                                        "11", "12", "13"};
    return ranks[rank];
}

std::string Card::getSuit(const Card::Suit suit) {
    static const std::string suits[] = {"♣", "♦", "♠", "♥"};
    return suits[suit];
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << Card::getRank(card.rank) << Card::getSuit(card.suit);
    return os;
}

std::string Card::toString() const {
    return getRank(rank) + getSuit(suit);
}
