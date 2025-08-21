//
// Created by Katie He on 6/9/25.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
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
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    vector<int> cows(n);
    for(int i = 0; i < n; ++i)
        cin >> cows[i];
    cout << firstTrue(1, n, [&](int k)
    {
        //cout << "k is " << k << endl;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; ++i)
        {
            pq.push(cows[i]);
        }
        for(int i = k; i < n; ++i)
        {
            int smallest = pq.top();
            pq.pop();
            //cout << smallest << endl;
            pq.push(smallest + cows[i]);
        }
        //cout << "time ends up as " << time << endl;
        for(int i = 0; i < k - 1; ++i)
        {
            pq.pop();
        }
        int time = pq.top();
        return time <= t;
    }) << endl;
}