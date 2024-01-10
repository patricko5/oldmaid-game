#include "gtest/gtest.h"
#include "OldMaid.h"
#include "Deck.h"
#include "Player.h"
#include "GameUI.h"
#include "OldMaidUI.h"
#include "OldMaidDeck.h"


#include <memory>

TEST(TestOldMaid, DealCardsTest) {
    Deck deck;
    deck.create(); 
    OldMaidUI ui;  
    OldMaid game(&ui, &deck);

    std::vector<Player*> players;
    players.push_back(new Player("Alice"));
    players.push_back(new Player("Bob"));

    unsigned int initialDeckSize = deck.size();

    game.dealCards(players);

    int totalCardsDealt = 0;
    for (auto player : players) {
        auto hand = player->getHand();
        unsigned int handSize = hand->size();
        totalCardsDealt += handSize;
    }

    EXPECT_EQ(totalCardsDealt, initialDeckSize);

    for (auto player : players) {
        delete player;
    }
}

TEST(TestOldMaid, GameIsOverTest)
{
    OldMaidDeck deck;
    OldMaidUI ui;
    OldMaid game(&ui, &deck);

    Player *alice = new Player("Alice");
    Player *bob = new Player("Bob");

    game.addPlayer(alice);
    game.addPlayer(bob);

    EXPECT_FALSE(game.isOver());

    delete alice;
    delete bob;
}