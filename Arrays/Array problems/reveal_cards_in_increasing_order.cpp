/*You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1. Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    int n = deck.size();
    sort(deck.begin(), deck.end());
    vector<int> ans(n);
    deque<int> d;
    for (int i = 0; i < n; i++)
        d.push_back(i);

    for (int card : deck)
    {
        int ind = d.front();
        d.pop_front();
        ans[ind] = card;
        if (!d.empty())
        {
            d.push_back(d.front());
            d.pop_front();
        }
    }
    return ans;
}