//
// Created by Katie He on 6/28/25.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    ll maxSum = 0;
    priority_queue<int> nums;
    for(int i = 0; i < n / 2; ++i)
    {
        nums.push(arr[n - 1 - 2*i]);
        nums.push(arr[n - 2*i - 2]);
        maxSum += nums.top();
        nums.pop();
    }
    cout << maxSum << endl;
}