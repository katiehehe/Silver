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
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> times(n);
    for(int i = 0; i < n; ++i)
        cin >> times[i];
    sort(times.begin(), times.end());
    cout << (firstTrue(0, times[n - 1] - times[0], [&](int x)
    {
        int groupStart = times[0];
        int groupNum = 1;
        int index = 1;
        while(index < n)
        {
            if(times[index] - groupStart > x)
            {
                ++groupNum;
                groupStart = times[index];
            }
            ++index;
        }
        if(groupNum <= k)
            return true;
        return false;
    }) + 1) / 2 << endl;
}