//
// Created by Katie He on 3/20/25.
//

#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int k, n;
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    cin >> n >> k;
    vector<vector<int>> paint(1001, vector<int>(1002));
    for(int i = 0; i < n; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j < x2; ++j)
        {
            ++paint[j][y1];
            --paint[j][y2];
        }
    }
    int count = 0;
    for(int i = 0; i < 1001; ++i)
    {
        int count1 = 0;
        for(int j = 0; j < 1001; ++j)
        {
            count1 += paint[i][j];
            if(count1 == k)
                ++count;
        }
    }
    cout << count << endl;
}