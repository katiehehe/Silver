//
// Created by Katie He on 6/21/25.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> peaks(n, vector<int>(2));
    for(int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        peaks[i][0] = a - b;
        peaks[i][1] = a + b;
    }
    sort(peaks.begin(), peaks.end(), [](const vector<int>& a, const vector<int>& b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    });
    int peakCount = 0;
    int mostRight = -1e9;
    for(int i = 0; i < n; ++i)
    {
        if(peaks[i][1] > mostRight)
            ++peakCount;
        mostRight = max(mostRight, peaks[i][1]);
    }
    cout << peakCount << endl;
}