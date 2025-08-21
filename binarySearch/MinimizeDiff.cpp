//
// Created by Katie He on 6/14/25.
//

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<long long> prefix(n + 1);
    for(int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + arr[i - 1];
    long long high = arr[n - 1] - arr[0];
    long long low = 0;
    while(low < high)
    {
        long long sumRequired = LLONG_MAX;
        long long mid = low + (high - low) / 2;
        for(int l = 0; l < n; ++l)
        {
            long long above = arr.end() - upper_bound(arr.begin(), arr.end(), arr[l] + mid);
            long long aboveSum = (prefix[n] - prefix[n - above]) - above * (arr[l] + mid);
            long long belowSum = 1LL * l * arr[l] - prefix[l];
            sumRequired = min(sumRequired, aboveSum + belowSum);
        }
        for(int r = 0; r < n; ++r)
        {
            long long aboveSum = (prefix[n] - prefix[r + 1]) - 1LL * (n - r - 1) * arr[r];
            long long below = upper_bound(arr.begin(), arr.end(), arr[r] - mid) - arr.begin();
            long long belowSum = 1LL * below * (arr[r] - mid) - prefix[below];
            sumRequired = min(sumRequired, aboveSum + belowSum);
        }
        if(sumRequired <= k)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << high << endl;
}