//
// Created by Katie He on 6/25/25.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> elsie(n / 2);
    vector<int> elsie2(n / 2);
    vector<bool> cards(2 * n + 1);
    for(int i = 0; i < n / 2; ++i)
    {
        int k;
        cin >> k;
        cards[k] = true;
        elsie[i] = k;
    }
    for(int i = 0; i < n / 2; ++i)
    {
        int k;
        cin >> k;
        cards[k] = true;
        elsie2[i] = k;
    }
    vector<int> bessie;
    for(int i = 1; i < 2 * n + 1; ++i)
    {
        if(!cards[i])
        {
            bessie.push_back(i);
        }
    }
    vector<int> bessieF(n / 2);
    vector<int> bessieB(n / 2);
    for(int i = 0; i < n / 2; ++i)
    {
        bessieB[i] = bessie[n / 2 - 1 - i];
    }
    for(int i = n - 1; i >= n / 2; --i)
    {
        bessieF[i - n / 2] = bessie[i];
    }
    int total = 0;
    int e = 0;
    int b = 0;
    sort(elsie.begin(), elsie.end());
    sort(elsie2.rbegin(), elsie2.rend());
    //for(int i : bessieF)
    //    cout << i << endl;
    //for(int i : bessieB)
    //    cout << i << endl;
    while(b < n / 2)
    {
        if(elsie[e] < bessieF[b])
        {
            ++total;
            ++e;
            ++b;
        }
        else
        {
            ++b;
        }
    }
    e = 0;
    b = 0;
    while(b < n / 2)
    {
        if(elsie2[e] > bessieB[b])
        {
            ++total;
            ++e;
            ++b;
        }
        else
        {
            ++b;
        }
    }
    cout << total << endl;
}