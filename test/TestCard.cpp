#include "gtest/gtest.h"
#include "Card.h"
#include <sstream> 

TEST(TestCard, ConstructorTest) {
    Card card(Card::SPADE, Card::ACE);

    EXPECT_EQ(card.rank, Card::ACE);
    EXPECT_EQ(card.suit, Card::SPADE);
}

TEST(TestCard, ToStringTest) {
    Card card(Card::HEART, Card::TEN);

    EXPECT_EQ(card.toString(), "10♥");
}

TEST(TestCard, CardRankSuitTest) {
    Card card(Card::DIAMOND, Card::KING);

    EXPECT_EQ(Card::getSuit(card.suit), "♦");
    EXPECT_EQ(Card::getRank(card.rank), "13");

    EXPECT_EQ(card.toString(), "13♦");
}

TEST(TestCard, EqualityOperatorTest) {
    Card card1(Card::DIAMOND, Card::KING);
    Card card2(Card::DIAMOND, Card::KING);

    EXPECT_TRUE(card1.rank == card2.rank);
}

TEST(TestCard, ComparisonOperatorTest) {
    Card lowerCard(Card::HEART, Card::TWO);
    Card higherCard(Card::HEART, Card::THREE);

    EXPECT_TRUE(lowerCard.rank < higherCard.rank);
    EXPECT_FALSE(lowerCard.rank > higherCard.rank);
}

TEST(TestCard, CopyConstructorTest) {
    Card originalCard(Card::SPADE, Card::ACE);
    Card copiedCard(originalCard);

    EXPECT_EQ(copiedCard.rank, originalCard.rank);
    EXPECT_EQ(copiedCard.suit, originalCard.suit);
}

