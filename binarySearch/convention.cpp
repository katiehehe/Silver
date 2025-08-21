//
// Created by Katie He on 6/9/25.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int firstTrue(int low, int high, function<bool(int)> f)
{
    high++;
    while(low < high)
    {
        int mid = (low + high) / 2;
        if(f(mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> times(n);
    for(int i = 0; i < n; ++i)
        cin >> times[i];
    sort(times.begin(), times.end());
    cout << firstTrue(0, times[times.size() - 1] - times[0], [&](int x)
    {
        int groupStart = times[0];
        int groupSize = 1;
        int groupNum = 1;
        int index = 0;
        while(index < n - 1)
        {
            if(times[index + 1] - groupStart <= x && groupSize <= c - 1)
            {
                ++groupSize;
            }
            else
            {
                ++groupNum;
                groupSize = 1;
                groupStart = times[index + 1];
            }
            ++index;
        }
        if(groupNum <= m)
            return true;
        return false;
    }) << endl;
}