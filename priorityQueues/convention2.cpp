//
// Created by Katie He on 6/28/25.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main()
{
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> cows(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> cows[i].first.first >> cows[i].first.second;
        cows[i].second = i;
    }
    sort(cows.begin(), cows.end());
    using Room = tuple<int, int, int>;
    priority_queue<Room, vector<Room>, greater<Room>> pq;
    int index = 0;
    int maxWait = 0;
    int endTime = 0;
    while(index < n || !pq.empty())
    {
        if(pq.empty())
        {
            endTime = cows[index].first.first + cows[index].first.second;
            ++index;
            while(index < n && cows[index].first.first <= endTime)
            {
                pq.push(make_tuple(cows[index].second, cows[index].first.first, cows[index].first.second));
                ++index;
            }
        }
        else
        {
            maxWait = max(maxWait, endTime - get<1>(pq.top()));
            endTime = endTime + get<2>(pq.top());
            pq.pop();
            while(index < n && cows[index].first.first <= endTime)
            {
                pq.push(make_tuple(cows[index].second, cows[index].first.first, cows[index].first.second));
                ++index;
            }
        }
    }
    cout << maxWait << endl;
}