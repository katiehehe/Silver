//
// Created by Katie He on 3/17/25.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> left(n);
    vector<int> right(n);
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    left[0] = nums[0];
    right[n - 1] = nums[n - 1];
    for(int i = 0; i < n - 1; ++i)
    {
        left[i + 1] = gcd(left[i], nums[i + 1]);
    }
    for(int i = n - 1; i > 0; --i)
    {
        right[i - 1] = gcd(right[i], nums[i - 1]);
    }
    int max1 = max(left[n - 2], right[1]);
    for(int i = 1; i < n - 1; ++i)
    {
        if(gcd(left[i - 1], right[i + 1]) > max1)
            max1 = gcd(left[i - 1], right[i + 1]);
    }
    cout << max1 << endl;
}