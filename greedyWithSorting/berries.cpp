//
// Created by Katie He on 6/25/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> trees(n);
    int maxBerries2 = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> trees[i];
        maxBerries2 = max(maxBerries2, trees[i]);
    }
    int maxBerries = 0;
    for(int i = 1; i <= maxBerries2; ++i)
    {
        int count = 0;
        vector<int> remainder;
        for(int j = 0; j < n; ++j)
        {
            count += trees[j] / i;
            remainder.push_back(trees[j] % i);
        }
        if(count < k / 2)
        {
            break;
        }
        if(count >= k)
        {
            maxBerries = max(maxBerries, k * i / 2);
            continue;
        }
        sort(remainder.rbegin(), remainder.rend());
        int sum = 0;
        for(int x = 0; x < k - count && x < (int)remainder.size(); ++x)
        {
            sum += remainder[x];
        }
        maxBerries = max(maxBerries, i * (count - k / 2) + sum);
    }
    cout << maxBerries << endl;
}