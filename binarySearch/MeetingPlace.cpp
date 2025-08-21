//
// Created by Katie He on 6/12/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(2, vector<int>(n));
    int minV = 1e9;
    int maxX = 1;
    int minX = 1e9;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[0][i];
        minX = min(minX, arr[0][i]);
        maxX = max(maxX, arr[0][i]);
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[1][i];
        minV = min(minV, arr[1][i]);
    }
    double high = (1.0 * (maxX - minX)) / minV;
    double low = 0;
    while(high - low > 1e-6)
    {
        double mid = (high + low) / 2;
        double minPos = 1;
        double maxPos = 1e9;
        for(int i = 0; i < n; ++i)
        {
            minPos = max(minPos, arr[0][i] - mid * arr[1][i]);
            maxPos = min(maxPos, arr[0][i] + mid * arr[1][i]);
        }
        if(maxPos >= minPos)
        {
            high = mid;
        }
        else
            low = mid;
    }
    cout << fixed << setprecision(12) << low << endl;
}