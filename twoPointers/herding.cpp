//
// Created by Katie He on 6/6/25.
//



#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> pos(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
    int minPos = pos[0];
    for(int& i : pos)
        i -= minPos;
    // min time
    int r = 0;
    int max1 = 0;
    for(int l = 0; l < n; ++l)
    {
        while(r + 1 < n && pos[r + 1] <= pos[l] + n - 1)
        {
            ++r;
        }
        if(l == 0 && r == n - 2 && pos[r] == n - 2 && pos[n - 1] - pos[n - 2] >= 3)
        {
            max1 = n - 2;
            break;
        }
        if(r == n - 1 && pos[r] != pos[l] + n - 1)
            break;
        max1 = max(max1, r - l + 1);
    }
    int left = n - 1;
    for(int right = n - 1; right >= 0; --right)
    {
        while(left - 1 >= 0 && pos[left - 1] >= pos[right] - (n - 1))
        {
            --left;
        }
        if(right == n - 1 && left == 1 && pos[left] == pos[n - 1] - (n - 2) && pos[1] - pos[0] >= 3)
        {
            max1 = n - 2;
            break;
        }
        if(left == 0 && pos[left] != pos[right] - (n - 1))
            break;
        max1 = max(max1, right - left + 1);
    }
    cout << n - max1 << endl;
    // max time
    int max2 = 0;
    if(pos[0] + 1 == pos[1] || pos[n - 2] + 1 == pos[n - 1])
        max2 = pos[n - 1] + 1 - n;
    else
    {
        int min1 = min(pos[1] - pos[0] - 1, pos[n - 1] - pos[n - 2] - 1);
        max2 = pos[n - 1] + 1 - n - min1;
    }
    cout << max2 << endl;
}