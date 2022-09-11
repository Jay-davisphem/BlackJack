#include <iostream>
#include "cards.h"

int main()
{
  auto deck{ createDeck() };

  shuffleDeck(deck);

  printDeck(deck);

  Card card{ CardRank::rank_jack, CardSuit::spade };
  printCard(card);
  std::cout << '\n' << getCardValue(card) << '\n';

  return 0;
}
