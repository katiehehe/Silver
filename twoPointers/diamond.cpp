//
// Created by Katie He on 6/5/25.
//

#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> sizes(n);
    for(int i = 0; i < n; ++i)
        cin >> sizes[i];
    sort(sizes.begin(), sizes.end());
    vector<int> most(n);
    int j = 0;
    for(int i = 0; i < n; ++i)
    {
        while(j < n && sizes[j] <= sizes[i] + k)
            ++j;
        most[i] = j - i;
    }
    int max1 = 0;
    int r = 0;
    for(int l = 0; l < n; ++l)
    {
        while(r < n && sizes[r] <= sizes[l] + k)
            ++r;
        int maxAfter;
        if(r < n)
            maxAfter = *max_element(most.begin() + r, most.end());
        else
            maxAfter = 0;
        max1 = max(max1, maxAfter + most[l]);
    }
    cout << max1 << endl;
}
