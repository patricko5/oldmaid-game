#include "gtest/gtest.h"
#include "Deck.h"
#include "Card.h"

TEST(TestDeck, CreateDeckTest) {
    Deck deck;
    deck.create();
    EXPECT_EQ(deck.size(), 52);  
    deck.clearDeck();
}

TEST(TestDeck, AddCardTest) {
    Deck deck;
    deck.addCard(new Card(Card::HEART, Card::ACE));
    EXPECT_EQ(deck.size(), 1);
    deck.clearDeck();
}

TEST(TestDeck, ClearDeckTest) {
    Deck deck;
    deck.create();
    deck.clearDeck();
    EXPECT_EQ(deck.size(), 0);
}

TEST(TestDeck, ShuffleDeckTest) {
    Deck deck;
    deck.create();
    deck.shuffle();
    EXPECT_EQ(deck.size(), 52);
    deck.clearDeck();
}

TEST(TestDeck, GetCardTest) {
    Deck deck;
    deck.create();
    Card* card = deck.getCard();
    EXPECT_TRUE(card != nullptr);
    EXPECT_EQ(deck.size(), 51);
    delete card;
    deck.clearDeck();
}