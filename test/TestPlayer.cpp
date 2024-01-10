#include "gtest/gtest.h"
#include "Player.h"
#include "Card.h"

TEST(TestPlayer, AddAndGetCardTest) {
    Player player("Alice");
    player.addCard(new Card(Card::HEART, Card::ACE)); 
    player.addCard(new Card(Card::DIAMOND, Card::ACE)); 

    EXPECT_EQ(player.getHand()->size(), 2);

    Card* removedCard = player.getCard(0);
    EXPECT_TRUE(removedCard != nullptr);
    EXPECT_EQ(player.getHand()->size(), 1);

    delete removedCard; 
}

TEST(TestPlayer, CheckAndRemovePairsTest) {
    Player player2("Bob");
    player2.addCard(new Card(Card::HEART, Card::KING)); 
    player2.addCard(new Card(Card::SPADE, Card::KING)); 
    player2.addCard(new Card(Card::DIAMOND, Card::QUEEN)); 

    player2.checkAndRemovePairs();

    EXPECT_EQ(player2.getHand()->size(), 1);
}

TEST(TestPlayer, DisplayCollectedPairsTest) {
    Player player("Charlie");
    player.addCard(new Card(Card::CLUB, Card::TEN)); 
    player.addCard(new Card(Card::DIAMOND, Card::TEN)); 

    player.checkAndRemovePairs();

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    player.displayCollectedPairs();
    std::cout.rdbuf(old); 

    std::string expectedOutput = "Charlie's pairs: 10♣ & 10♦\n";
    EXPECT_EQ(buffer.str(), expectedOutput);
}

