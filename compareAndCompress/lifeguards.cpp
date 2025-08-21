//
// Created by Katie He on 6/21/25.
//

#include <iostream>
#include <tuple>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using ll = long long;
using namespace std;

int main()
{
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin >> n;
    vector<tuple<ll, int, int>> times;
    for(int i = 0; i < n; ++i)
    {
        ll a, b;
        cin >> a >> b;
        times.push_back({a, 1, i});
        times.push_back({b, -1, i});
    }
    sort(times.begin(), times.end());
    vector<ll> singleTimes(n);
    set<int> ints;
    ll totalTime = 0;
    for(int i = 0; i < 2 * n - 1; ++i)
    {
        if(get<1>(times[i]) == 1)
            ints.insert(get<2>(times[i]));
        else
            ints.erase(get<2>(times[i]));
        if(ints.size() > 0)
        {
            totalTime += get<0>(times[i + 1]) - get<0>(times[i]);
            if(ints.size() == 1)
            {
                singleTimes[*ints.begin()] += get<0>(times[i + 1]) - get<0>(times[i]);;
            }
        }
    }
    ll minTime = 1e9;
    for(ll x : singleTimes)
        minTime = min(x, minTime);
    //cout << totalTime << endl;
    //cout << minTime << endl;
    cout << totalTime - minTime << endl;
}