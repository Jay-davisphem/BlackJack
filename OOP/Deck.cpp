#include <iostream>
#include <ctime>
#include <random>
#include <cassert>
#include <algorithm>
#include "Deck.h"
void Deck::print() const
{
  for (const auto& card : m_deck)
  {
    card.print();
    std::cout << ' ';
  }

  std::cout << '\n';
}

void Deck::shuffle()
{
  static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

  std::shuffle(m_deck.begin(), m_deck.end(), mt);

  m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
  assert(m_cardIndex < m_deck.size());
  return m_deck[m_cardIndex++];
}
