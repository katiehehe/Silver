//
// Created by Katie He on 6/8/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    long long i = n / 2;
    //cout << i << endl;
    long long sum = 0;
    while(i + 1 < n && sum + (arr[i + 1] - arr[i]) * (i + 1 - n / 2) <= k)
    {
        sum += (arr[i + 1] - arr[i]) * (i + 1 - n / 2);
        ++i;
        //cout << i << " with sum of " << sum << endl;
    }
    int step = i - n / 2 + 1;
    //cout << step << endl;
    cout << arr[i] + ((k - sum) / step) << endl;
}