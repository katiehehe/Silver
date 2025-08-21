//
// Created by Katie He on 6/24/25.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> bCards(n);
    vector<int> bOrder(n);
    set<int> eCards;
    for(int i = 0; i < n; ++i)
    {
        cin >> bCards[i];
        bOrder[i] = bCards[i];
    }
    bCards.push_back(0);
    bCards.push_back(2 * n + 1);
    sort(bCards.begin(), bCards.end());
    //for(int i : bCards)
    //    cout << i << endl;
    for(int i = 0; i < n + 1; ++i)
    {
        for(int j = bCards[i] + 1; j < bCards[i + 1]; ++j)
        {
            eCards.insert(j);
        }
    }
    //for(int i : eCards)
    //    cout << i << endl;
    int wins = 0;
    for(int i = 0; i < n; ++i)
    {
        auto it = eCards.lower_bound(bOrder[i]);
        if(it == eCards.end())
        {
            eCards.erase(eCards.begin());
        }
        else
        {
            eCards.erase(it);
            ++wins;
        }
    }
    cout << wins << endl;
}