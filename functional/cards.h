#ifndef CARDS_H
#define CARDS_H

#include <array>

enum class CardSuit
{
    club,
    diamond,
    heart,
    spade,

    max_suits
};

enum class CardRank
{
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    rank_ace,

    max_ranks
};

struct Card
{
  CardRank rank{};
  CardSuit suit{};
};

void printCard(const Card& card);

// We'll need these many more times, create an aliases.

using deck_type = std::array<Card, 52>;
using index_type = deck_type::size_type;

deck_type createDeck();

void printDeck(const deck_type& deck);

void shuffleDeck(deck_type& deck);

int getCardValue(const Card& card);

#endif
