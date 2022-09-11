#include <algorithm> // std::shuffle
#include <array>
#include <cassert>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt199
#include "cards.h"

struct Player
{
    int score{};
    int ace{};
};

enum class BlackjackResult
{
    player_win,
    dealer_win,
    tie
};

constexpr int g_maximumScore{ 21 };

// Minimum score that the dealer has to have.
constexpr int g_minimumDealerScore{ 17 };

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

void removeAce(Player& bettor){
  if (bettor.ace > 0 && bettor.score > g_maximumScore){
    bettor.score -= 10;
    bettor.ace -= 1;
  }
}
// Returns true if the player went bust. False otherwise.
bool playerTurn(const deck_type& deck, index_type& nextCardIndex, Player& player)
{
    while (true)
    {
        removeAce(player);
        if (player.score > g_maximumScore)
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                int cardValue{ getCardValue(deck.at(nextCardIndex++)) };
                if (cardValue == 11)
                  player.ace += 1;
                player.score += cardValue;
                std::cout << "You were dealt a " << cardValue << " and now have " << player.score << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(const deck_type& deck, index_type& nextCardIndex, Player& dealer)
{
    // Draw cards until we reach the minimum value.
    while (dealer.score < g_minimumDealerScore)
    {
        removeAce(dealer);  
        int cardValue{ getCardValue(deck.at(nextCardIndex++)) };
        if (cardValue == 11)
          dealer.ace += 1;
        dealer.score += cardValue;
        std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer.score << '\n';

    }

    // If the dealer's score is too high, they went bust.
    if (dealer.score > g_maximumScore)
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

BlackjackResult playBlackjack(const deck_type& deck)
{
    // Index of the card that will be drawn next. This cannot overrun
    // the array, because a player will lose before all cards are used up.
    index_type nextCardIndex{ 0 };

    // Create the dealer and give them 1 card.
    Player dealer{ getCardValue(deck.at(nextCardIndex++)) };

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.score << '\n';

    // Create the player and give them 2 cards.
    Player player{ getCardValue(deck.at(nextCardIndex)) + getCardValue(deck.at(nextCardIndex + 1)) };
    nextCardIndex += 2;

    std::cout << "You have: " << player.score << '\n';

    if (playerTurn(deck, nextCardIndex, player) || player.score < dealer.score)
    {
        // The player went bust.
        return BlackjackResult::dealer_win;
    }

    if (dealerTurn(deck, nextCardIndex, dealer) || player.score > dealer.score)
    {
        // The dealer went bust, the player wins.
        return BlackjackResult::player_win;
    }

    return BlackjackResult::tie;
}

bool getYOrNo()
{
    while (true)
    {
        std::cout << "\nWannado go again? y or n: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        }
    }
}

void rounds()
{
  do{
  auto deck{ createDeck() };
  shuffleDeck(deck);

  if (playBlackjack(deck) == BlackjackResult::player_win)
    {
        std::cout << "You win!\n";
    }
    else if(playBlackjack(deck) == BlackjackResult::dealer_win)
    {
        std::cout << "You lose!\n";
    }
    else{
      std::cout << "It's a tie!\n";
    }

  }
  while(getYOrNo());
}

int main()
{
  rounds();
}
