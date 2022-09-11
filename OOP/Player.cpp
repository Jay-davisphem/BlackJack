#include "Player.h"
int Player::drawCard(Deck& deck)
{
  int value = deck.dealCard().value();
  m_score += value;
  return value;
}
