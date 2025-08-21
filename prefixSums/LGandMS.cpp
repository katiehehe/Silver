//
// Created by Katie He on 5/25/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    sort(nums.rbegin(), nums.rend());
    vector<int> freqs(n + 2);
    for(int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        ++freqs[l];
        --freqs[r + 1];
    }
    for(int i = 1; i < n + 1; ++i)
    {
        freqs[i] += freqs[i - 1];
    }
    sort(freqs.rbegin(), freqs.rend());
    ll sum = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += ((ll)(nums[i])) * freqs[i];
    }
    cout << sum << endl;
    return 0;
}