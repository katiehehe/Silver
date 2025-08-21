//
// Created by Katie He on 6/28/25.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int c, n;
    cin >> c >> n;
    vector<int> chickens(c);
    vector<pair<int, int>> cows(n);
    for(int i = 0; i < c; ++i)
        cin >> chickens[i];
    for(int i = 0; i < n; ++i)
        cin >> cows[i].first >> cows[i].second;
    sort(chickens.begin(), chickens.end());
    sort(cows.begin(), cows.end());
    int chickIndex = 0;
    int cowIndex = 0;
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    //cout << "hi" << endl;
    while(chickIndex < c)
    {
        while(cowIndex < n && cows[cowIndex].first <= chickens[chickIndex])
        {
            if(cows[cowIndex].second >= chickens[chickIndex])
            {
                pq.push(cows[cowIndex].second);
            }
            ++cowIndex;
        }
        while(!pq.empty() && pq.top() < chickens[chickIndex])
        {
            pq.pop();
        }
        if(pq.empty())
        {
            ++chickIndex;
            continue;
        }
        ++count;
        ++chickIndex;
        pq.pop();
        //cout << "hi" << endl;
    }
    cout << count << endl;
}