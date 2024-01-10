
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

#include "Game.h"
#include "Card.h"
#include "Deck.h"
#include "GameUI.h"
#include "Player.h"

Game::~Game()
{
    // Cleanup any dynamic memory or resources if necessary.
}

void Game::addPlayer(Player *player)
{
    players.push_back(player);
}

std::vector<Player *> Game::getPlayers()
{
    return players;
}

void Game::start()
{
    // Game Introduction
    std::cout << "<<--------------------------------------------------->>\n";
    std::cout << "Welcome to Old Maid!\n";
    std::cout << "The goal is to form and discard pairs of cards,\n";
    std::cout << "and avoid being left with the unmatchable 'Old Maid'.\n";
    std::cout << "<<--------------------------------------------------->>\n\n";

    // Shuffling and Dealing Announcement
    std::cout << "Shuffling cards...\n";
    deck->shuffle();
    std::cout << "Dealing cards to players...\n";
    dealCards(players);
    std::cout << "Cards have been dealt. Let the game begin!\n\n";

    // Main game loop
    while (!isOver())
    {

        for (unsigned int i = 0; i < players.size(); ++i)
        {
            players[0]->checkAndRemovePairs();
            players[1]->checkAndRemovePairs();

            // Debugger
             std::cout << std::endl;
             for (auto &player : players)
             {
                 std::cout << "" << player->name << "'s hand: ";
                 for (Card *card : *(player->getHand()))
                 {
                     std::cout << *card << ", ";
                 }
                 std::cout << std::endl;
             }

            // Skip players who are out of the game
            if (std::find(playersGoneOut.begin(), playersGoneOut.end(), players[i]) != playersGoneOut.end())
            {
                continue;
            }
            // Check if the player's hand is empty
            if (players[i]->getHand()->empty())
            {
                std::cout << players[i]->name << "'s hand is empty." << std::endl;
                continue; // Skip the turn if the hand is empty
            }

            // The next player to draw from (wrapping around to the first player if necessary)
            Player *nextPlayer = players[(i + 1) % players.size()];

            // Check if the next player has cards to draw from
            if (!nextPlayer->getHand()->empty())
            {
                std::cout << "-------------------------------------------------------" << std::endl;
                std::cout << "" << std::endl;
                std::cout << "" << players[i]->name << "'s turn." << std::endl;
                // Let the current player draw a card from the next player
                unsigned int cardIndex = ui->requestCard(nextPlayer, nextPlayer->getHand());

                // Validate the chosen card index
                if (cardIndex >= 0 && cardIndex < nextPlayer->getHand()->size())
                {
                    Card *drawnCard = nextPlayer->getCard(cardIndex);

                    // Add the drawn card to the current player's hand
                    players[i]->addCard(drawnCard);
                }
                else
                {
                    std::cout << "Try again." << std::endl;
                    i--; // Repeat the turn for invalid choice
                    continue;
                }
            }

            // Check if the current player is out of the game
            checkIfPlayerOut();
        }
    }

    // End game logic
    ui->showGameOutcome(players);
}

void Game::checkIfPlayerOut()
{
    for (auto &player : players)
    {
        if (player->getHand()->empty())
        {
            playersGoneOut.push_back(player);
        }
    }
}

bool Game::hasSet(std::list<Card *> *hand, unsigned int size)
{
    return false;
}

bool Game::isOver()
{
    int totalCards = 0;
    for (auto &player : players)
    {
        totalCards += player->getHand()->size();
    }
    std::cout << "Total cards left: " << totalCards << std::endl; // Debug print
    return totalCards == 1;
}

void Game::printPlayerHand(Player *player)
{
    auto hand = player->getHand();
    for (auto it = hand->begin(); it != hand->end(); ++it)
    {
        std::cout << **it;
        if (std::next(it) != hand->end())
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl; 
}
