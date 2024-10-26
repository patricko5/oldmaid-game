#include "OldMaid.h"
#include "OldMaidUI.h"  
#include "OldMaidDeck.h" 
#include "Player.h"

int main()
{
   OldMaidUI *ui = new OldMaidUI(); // Create the user interface
   OldMaidDeck *deck = new OldMaidDeck(); // Create the deck

   deck->create(); // Create and prepare the deck

   OldMaid *game = new OldMaid(ui, deck); // Create the game

   // Add players to the game
   game->addPlayer(new Player("Player 1"));
   game->addPlayer(new Player("Player 2"));
   // Add more players as needed

   // Start the game
   game->start();

   delete game;
   delete ui;
   delete deck;

   return 0;
}
