//
// Created by Katie He on 6/22/25.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;
    map<ll, ll> updates;
    vector<pair<ll, ll>> queries;
    for(int i = 0; i < n; ++i)
    {
        ll l, r, v;
        cin >> l >> r >> v;
        updates[l] += v;
        updates[r] -= v;
    }
    for(int i = 0; i < q; ++i)
    {
        ll l, r;
        cin >> l >> r;
        updates[l];
        updates[r];
        queries.push_back({l, r});
    }
    ll sum = 0;
    for(auto& [key, val] : updates)
    {
        sum += val;
        val = sum;
    }
    map<ll, ll> secondSum;
    ll currSum = 0;
    for(auto it = updates.begin(); it != updates.end(); ++it)
    {
        if(it != updates.begin())
        {
            auto prev = std::prev(it);
            currSum += prev->second * (it->first - prev->first);
        }
        secondSum[it->first] = currSum;
    }
    for(auto& x : queries)
    {
        cout << secondSum[x.second] - secondSum[x.first] << endl;
    }
}