#ifndef _DECK_H_
#define _DECK_H_
#include <array>
#include "Card.h"
class Deck
{
public:
    using array_type = std::array<Card, 52>;
    using index_type = array_type::size_type;

private:
    array_type m_deck{};
    index_type m_cardIndex{ 0 };

public:
    Deck()
    {
        index_type index{ 0 };

        for (int suit{ 0 }; suit < Card::max_suits; ++suit)
        {
            for (int rank{ 0 }; rank < Card::max_ranks; ++rank)
            {
                m_deck[index] = { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) };
                ++index;
            }
        }
    }

    void print() const;

    void shuffle();

    const Card& dealCard();
};
#endif
