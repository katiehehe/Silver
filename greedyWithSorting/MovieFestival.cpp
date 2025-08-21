//
// Created by Katie He on 6/23/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        times.push_back({b, a});
    }
    sort(times.begin(), times.end());
    int lastTime = -1;
    int total = 0;
    for(int i = 0; i < n; ++i)
    {
        if(times[i].second >= lastTime)
        {
            lastTime = times[i].first;
            ++total;
        }
    }
    cout << total << endl;
}
