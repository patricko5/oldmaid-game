#ifndef GOFISH_H
#define GOFISH_H

#include <Game.h>
#include <vector>

class OldMaid : public Game {
 public:
    /**
    * Create a game of Old Maid using a UI and a deck.
    * @param ui The UI for the game.
    * @param deck The deck for the game.
    */
    OldMaid(GameUI* ui, Deck* deck) : Game(ui, deck) {}
    virtual ~OldMaid() {}
    void dealCards(std::vector<Player*> p);
    void beforeTurn(unsigned int playerNum, unsigned int numPlayers);
    void afterTurn(Player* currentPlayer, std::vector<Player*>* players,
                         Card* played);
    bool turnOver();
    bool isOver();
};

#endif // GOFISH_H
