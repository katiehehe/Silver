//
// Created by Katie He on 3/17/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> partial(n + 1);
    vector<int> net(n + 1); // change when moving from 1 index to next one
    for(int i = 0; i < k; ++i)
    {
        int f, l;
        cin >> f >> l;
        net[f - 1] += 1;
        net[l] -= 1;
    }
    for(int i = 0; i < n; ++i)
    {
        partial[i + 1] = partial[i] + net[i];
    }
    sort(partial.begin(), partial.end());
    cout << partial[(n + 1) / 2] << endl;
}