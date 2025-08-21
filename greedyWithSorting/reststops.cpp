//
// Created by Katie He on 6/25/25.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main()
{
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    int length, n, farmer, bessie;
    cin >> length >> n >> farmer >> bessie;
    vector<pair<ll, ll>> stops;
    for(int i = 0; i < n; ++i)
    {
        ll a, b;
        cin >> a >> b;
        stops.push_back({a, b});
    }
    stops.push_back({0, 0});
    ll total = 0;
    auto it = stops.begin();
    sort(stops.begin(), stops.end());
    while(true)
    {
        //cout << "hi" << endl;
        auto it2 = max_element(it + 1, stops.end(), [](const pair<ll, ll>& lhs, const pair<ll, ll>& rhs){
            return lhs.second < rhs.second;
        });
        if(it2 == stops.end())
        {
            break;
        }
        total += it2->second * (farmer - bessie) * (it2->first - it->first);
        it = it2;
    }
    cout << total << endl;
}