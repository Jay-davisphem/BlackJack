#include <iostream>
#include <cassert>
#include "Card.h"

void Card::print() const
{
  switch (m_rank)
  {
    case rank_2:        std::cout << '2';   break;
    case rank_3:        std::cout << '3';   break;
    case rank_4:        std::cout << '4';   break;
    case rank_5:        std::cout << '5';   break;
    case rank_6:        std::cout << '6';   break;
    case rank_7:        std::cout << '7';   break;
    case rank_8:        std::cout << '8';   break;
    case rank_9:        std::cout << '9';   break;
    case rank_10:       std::cout << 'T';   break;
    case rank_jack:     std::cout << 'J';   break;
    case rank_queen:    std::cout << 'Q';   break;
    case rank_king:     std::cout << 'K';   break;
    case rank_ace:      std::cout << 'A';   break;
    default:
                        std::cout << '?';
                        break;
  }

  switch (m_suit)
    {
      case club:          std::cout << 'C';   break;
      case diamond:       std::cout << 'D';   break;
      case heart:         std::cout << 'H';   break;
      case spade:         std::cout << 'S';   break;
      default:
                          std::cout << '?';
                          break;
    }
}
int Card::value() const
{
  switch (m_rank)
  {
    case rank_2:        return 2;
    case rank_3:        return 3;
    case rank_4:        return 4;
    case rank_5:        return 5;
    case rank_6:        return 6;
    case rank_7:        return 7;
    case rank_8:        return 8;
    case rank_9:        return 9;
    case rank_10:       return 10;
    case rank_jack:     return 10;
    case rank_queen:    return 10;
    case rank_king:     return 10;
    case rank_ace:      return 11;
    default:
                        assert(false && "should never happen");
                        return 0;
    }
}
