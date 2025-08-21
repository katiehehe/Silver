//
// Created by Katie He on 6/18/25.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> input(n, vector<int>(2));
    vector<int> times;
    // n
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        times.push_back(a);
        times.push_back(b);
        input[i][0] = a;
        input[i][1] = b;
    }
    // n log n
    sort(times.begin(), times.end());
    map<int, int> timeToIndex;
    // n log n
    for(int i = 0; i < 2*n; ++i)
    {
        timeToIndex[times[i]] = i;
    }
    vector<int> newArr(2*n);
    // n log n
    for(int i = 0; i < n; ++i)
    {
        ++newArr[timeToIndex[input[i][0]]];
        --newArr[timeToIndex[input[i][1]]];
    }
    //for(int i : times)
    //    cout << i << endl;
    int max1 = 0;
    int current = 0;
    // n
    for(int i = 0; i < 2*n; ++i)
    {
        current += newArr[i];
        max1 = max(current, max1);
    }
    cout << max1 << endl;
}