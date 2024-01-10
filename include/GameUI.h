#ifndef GAMEUI_H_INCLUDED
#define GAMEUI_H_INCLUDED

#include <list>
#include <vector>
#include "Card.h"
#include "Player.h"

class GameUI {
 public:
    GameUI() {}
    virtual ~GameUI() {}

    /**
    * Request a card from a player.
    * @param player The player requesting the card.
    * @param hand The hand of the player from whom the card is requested.
    */
    virtual unsigned int requestCard(Player* player,
                                     std::list<Card*>* hand) = 0;

    /**
    * Indicate that the player's turn failed (e.g. didn't get a matching card).
    */
    virtual void playFailed() = 0;

    /**
    * Indicate that the player's turn succeeded (e.g. got a matching card).
    */
    virtual void playSucceeded() = 0;

    /**
    * Show the outcome of the game (e.g. player scores)
    * @param players The players in the game.
    */
    virtual void showGameOutcome(std::vector<Player*> players) {}

    /**
    * Indicate that a player has left the game.
    * @param player The player who left the game.
    */
    virtual void outOfGame(Player* player) {}
};

#endif // GAMEUI_H_INCLUDED
