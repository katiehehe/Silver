//
// Created by Katie He on 6/29/25.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main()
{
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n, g;
    cin >> n >> g;
    vector<vector<int>> entries(n, vector<int>(3));
    for(int i = 0; i < n; ++i)
    {
        cin >> entries[i][0] >> entries[i][1] >> entries[i][2];
    }
    sort(entries.begin(), entries.end());
    map<int, int> cows;
    map<int, set<int>> vals;
    vals[0].insert(0);
    for(int i = 0; i < n; ++i)
    {
        cows[entries[i][1]] = 0;
        vals[0].insert(entries[i][1]);
    }
    int count = 0;
    int max = 0;
    for(int i = 0; i < n; ++i)
    {
        set<int> prevTop = vals[max];
        //cout << "hi" << endl;
        int cow = entries[i][1];
        int val = entries[i][2];
        vals[cows[cow]].erase(cow);
        if(vals[cows[cow]].empty())
        {
            vals.erase(cows[cow]);
        }
        cows[cow] += val;
        vals[cows[cow]].insert(cow);
        /*
        auto it = std::prev(vals.end());
        int lastKey = it->first;
        if(lastKey != max)
        {
            ++count;
            maxSize = it->second.size();
            max = lastKey;
        }
        else if(it->second.size() != maxSize)
        {
            ++count;
            maxSize = it->second.size();
        }
         */
        auto it = prev(vals.end());
        int newMax = it->first;
        set<int>& newTop = it->second;
        if (prevTop != newTop) ++count;
            max = newMax;  // update for next round
    }
    cout << count << endl;
}