#ifndef _PLAYER_H_
#define _PLAYER_H
#include "Deck.h"
#include "Constants.h"
class Player
{
  private:
    int m_score{};

  public:
    int drawCard(Deck& deck);
    int score() const
    {
      return m_score;
    }

    bool isBust() const
    {
      return (m_score > g_maximumScore);
    }
};
#endif
