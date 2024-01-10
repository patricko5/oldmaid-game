#include <iostream>
#include <vector>
#include <random>

#include "OldMaid.h"
#include "Deck.h"
#include "Card.h"

void OldMaid::dealCards(std::vector<Player *> players)
{
    deck->shuffle();

    std::random_device rd;  
    std::mt19937 rng(rd()); 
    std::uniform_int_distribution<unsigned int> uni(0, players.size() - 1);

    // Deal cards to players
    while (deck->size() > 0)
    {
        unsigned int currentPlayerIndex = uni(rng); 
        Card *card = deck->getCard();
        if (card == nullptr)
        {
            break;
        }
        players[currentPlayerIndex]->addCard(card);
    }
}

void OldMaid::beforeTurn(unsigned int playerNum, unsigned int numPlayers)
{
}

void OldMaid::afterTurn(Player *currentPlayer, std::vector<Player *> *players, Card *played)
{
}

bool OldMaid::turnOver()
{
    return true;
}

bool OldMaid::isOver()
{
    int totalCards = 0;
    for (auto &player : players)
    {
        totalCards += player->getHand()->size();
    }
    return totalCards == 1;
}
