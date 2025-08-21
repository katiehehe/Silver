//
// Created by Katie He on 6/21/25.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

struct Cost
{
    ll q;
    ll p;
    bool operator<(const Cost &c) const
    {
        return p < c.p;
    }
};

int main()
{
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    int n, m, r;
    cin >> n >> m >> r;
    vector<ll> cows(n);
    vector<Cost> costs;
    vector<ll> partial(r);
    for(int i = 0; i < n; ++i)
        cin >> cows[i];
    for(int i = 0; i < m; ++i)
    {
        ll a, b;
        cin >> a >> b;
        costs.push_back({a, b});
    }
    for(int i = 0; i < r; ++i)
    {
        cin >> partial[i];
    }
    sort(cows.rbegin(), cows.rend());
    sort(costs.rbegin(), costs.rend());
    sort(partial.rbegin(), partial.rend());
    for(int i = 1; i < r; ++i)
    {
        partial[i] += partial[i - 1];
    }
    ll canSell = 0;
    int farmer = 0;
    ll maxSell = 0;
    for(int i = 0; i <= n; ++i)
    {
        //ll currentSell = partial[min(n - i, r)];
        ll totalMilk = 0;
        if(i > 0)
            totalMilk = cows[i - 1];
        while(farmer < m && costs[farmer].q <= totalMilk)
        {
            totalMilk -= costs[farmer].q;
            canSell += costs[farmer].q * costs[farmer].p;
            ++farmer;
        }
        if(farmer < m)
        {
            costs[farmer].q -= totalMilk;
            canSell += costs[farmer].p * totalMilk;
        }
        //currentSell += canSell;
        if(i == n)
            maxSell = max(maxSell, canSell);
        else
            maxSell = max(maxSell, canSell + partial[min((n - i - 1), r - 1)]);
    }
    cout << maxSell << endl;
}