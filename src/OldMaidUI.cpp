#include "OldMaidUI.h"
#include <iostream>
#include <limits>

unsigned int OldMaidUI::requestCard(Player* player, std::list<Card*>* hand) {
    if (hand->empty()) {
        std::cout << player->name << " has no cards to draw." << std::endl;
        return 0; 
    } else {
        unsigned int handSize = hand->size();
        unsigned int choice;

        while (true) { // Loop until valid input is received
            std::cout << "Choose a card to draw (1 - " << handSize << "): ";
            std::cin >> choice;

            // Check for invalid input
            if (std::cin.fail() || choice < 1 || choice > handSize) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid choice. Please choose a number between 1 and " << handSize << "." << std::endl;
            } else {
                break; 
            }
        }
        return choice - 1; 
    }
}


void OldMaidUI::playFailed() {
    std::cout << "Play failed. No matching card found." << std::endl;
}

void OldMaidUI::playSucceeded() {
    std::cout << "Play succeeded! A matching card was found." << std::endl;
}

void OldMaidUI::showGameOutcome(std::vector<Player*> players) {
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "Game Over." << std::endl;

    // Identify the loser
    Player* loser = nullptr;
    for (auto& player : players) {
        if (!player->getHand()->empty()) {
            loser = player;
            break;
        }
    }

    if (loser) {
        std::cout << loser->name << " is left with the Old Maid and loses the game!" << std::endl;
    } else {
        std::cout << "Unexpected outcome: No player is left with the Old Maid." << std::endl;
    }

    for (auto& player : players) {
        if (player != loser) {
            std::cout <<"Congratulations " <<player->name << ", you successfully avoided the Old Maid." << std::endl;
        }
    }
    std::cout << "-------------------------------------------------------" << std::endl;
}

void OldMaidUI::outOfGame(Player* player) {
    std::cout << player->name << " is out of the game." << std::endl;
}
