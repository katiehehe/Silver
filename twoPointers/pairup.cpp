//
// Created by Katie He on 6/3/25.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int N;
    cin >> N;
    vector<vector<int>> cows(N, vector<int>(2));
    int total = 0;
    for(int i = 0; i < N; ++i)
    {
        cin >> cows[i][0] >> cows[i][1];
        total += cows[i][0];
    }
    sort(cows.begin(), cows.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    int l = 0;
    int r = N - 1;
    int max1 = 0;
    for(int i = 0; i < total / 2; ++i)
    {
        max1 = max(cows[l][1] + cows[r][1], max1);
        --cows[l][0];
        --cows[r][0];
        if(cows[l][0] == 0)
            ++l;
        if(cows[r][0] == 0)
            --r;
    }
    cout << max1 << endl;
}