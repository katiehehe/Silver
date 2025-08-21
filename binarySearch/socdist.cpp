//
// Created by Katie He on 6/10/25.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

long long lastTrue(long long low, long long high, function<bool(long long)> f)
{
    --low;
    while(low < high)
    {
        int mid = (low + high + 1) / 2;
        if(f(mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> pos(m);
    for(int i = 0; i < m; ++i)
    {
        cin >> pos[i].first >> pos[i].second;
    }
    sort(pos.begin(), pos.end());
    cout << lastTrue(1, pos[m - 1].second - pos[0].first, [&](long long d)
    {
        //cout << "d is equal to " << d << endl;
        int currInt = 0;
        long long currPos = pos[0].first;
        long long numOfCows = 0;
        while(currInt < m)
        {
            numOfCows += (pos[currInt].second - currPos) / d + 1;
            //cout << "current interval is " << currInt << ", current position is " << currPos << ", and we can fit " << (pos[currInt].second - currPos) / d + 1 << " in it" << endl;
            currPos += d * ((pos[currInt].second - currPos) / d + 1);
            //cout << "the next spot is " << currPos << endl;
            ++currInt;
            bool hi = false;
            while(currInt < m && pos[currInt].first <= currPos)
            {
                if(pos[currInt].second >= currPos)
                {
                    hi = true;
                    break;
                }
                ++currInt;
            }
            if(!hi && currInt < m)
            {
                currPos = pos[currInt].first;
            }
        }
        //cout << "there are a max of " << numOfCows << endl;
        return numOfCows >= n;
    }) << endl;
}