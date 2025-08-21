//
// Created by Katie He on 6/24/25.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> cows(n);
    for(int i = 0; i < n; ++i)
        cin >> cows[i];
    sort(cows.rbegin(), cows.rend());
    int total = 0;
    for(int i = 0; i < n; ++i)
    {
        if(total <= cows[i])
        {
            ++total;
        }
    }
    cout << total << endl;
}