#ifndef _UTILS_H_
#define _UTILS_H

#include "Deck.h"
#include "Player.h"

bool playerWantsHit();

// Returns true if the player went bust. False otherwise.
bool playerTurn(Deck& deck, Player& player);

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck& deck, Player& dealer);

bool playBlackjack(Deck& deck);


#endif
