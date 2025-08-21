//
// Created by Katie He on 6/28/25.
//

#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> sol;
    vector<tuple<int, int, int>> times;
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        times.push_back({a, b, i});
    }
    sort(times.begin(), times.end());
    std::priority_queue<
            std::pair<int,int>,                       // value type
            std::vector<std::pair<int,int>>,          // underlying container
            std::greater<std::pair<int,int>>          // comparator → min‑heap
    > pq;
    pq.push({get<1>(times[0]), 1});
    int currRoom = 1;
    sol.push_back({get<2>(times[0]), 1});
    for(int i = 1; i < n; ++i)
    {
        if(pq.top().first < get<0>(times[i]))
        {
            int x = pq.top().second;
            pq.pop();
            pq.push({get<1>(times[i]), x});
            sol.push_back({get<2>(times[i]), x});
        }
        else
        {
            ++currRoom;
            pq.push({get<1>(times[i]), currRoom});
            sol.push_back({get<2>(times[i]), currRoom});
        }
    }
    cout << currRoom << endl;
    sort(sol.begin(), sol.end());
    for(auto& i : sol)
        cout << i.second << " ";
    cout << endl;
}