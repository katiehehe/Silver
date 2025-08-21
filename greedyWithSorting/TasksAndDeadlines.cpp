//
// Created by Katie He on 6/24/25.
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> tasks;
    ll sum = 0;
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        sum += b;
        tasks.push_back({a, b});
    }
    sort(tasks.begin(), tasks.end());
    ll totalTimes = 0;
    for(int i = 0; i < n; ++i)
    {
        totalTimes += 1ll * tasks[i].first * (n - i);
    }
    cout << sum - totalTimes << endl;
}