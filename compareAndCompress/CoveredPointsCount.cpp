//
// Created by Katie He on 6/19/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr;
    for(int i = 0; i < n; ++i)
    {
        ll a, b;
        cin >> a >> b;
        arr.push_back({a, 1LL});
        arr.push_back({a + 1, 0});
        arr.push_back({b + 1, -1LL});
        arr.push_back({b, 0});
    }
    sort(arr.begin(), arr.end());
    vector<pair<ll, ll>> counts;
    ll currentIndex = -1;
    ll currentSum = 0;
    for(const pair<ll, ll>& p : arr)
    {
        //cout << p.first << " " << p.second << endl;
        if(currentIndex == -1)
        {
            currentIndex = p.first;
        }
        else if(p.first > currentIndex)
        {
            counts.push_back({currentIndex, currentSum});
            currentIndex = p.first;
        }
        currentSum += p.second;
    }
    counts.push_back({currentIndex, currentSum});
    //cout << endl;
    //for(const pair<ll, ll>& p : counts)
    //    cout << p.first << " " << p.second << endl;
    //cout << endl;
    vector<ll> numPoints(n);
    for(int i = 0; i < counts.size() - 1; ++i)
    {
        //cout << counts[i + 1].first - counts[i].first << endl;
        if(counts[i].second - 1 >= 0)
            numPoints[counts[i].second - 1] += counts[i + 1].first - counts[i].first;
    }
    for(ll i : numPoints)
        cout << i << " ";
}