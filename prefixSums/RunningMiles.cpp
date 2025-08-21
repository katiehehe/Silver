//
// Created by Katie He on 3/18/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int j = 0; j < n; ++j)
        {
            cin >> nums[j];
        }
        int maxSum = 0;
        vector<int> maxLeft(n);
        maxLeft[0] = nums[0];
        vector<int> maxRight(n);
        maxRight[n - 1] = nums[n - 1] - n + 1;
        for(int j = 1; j < n; ++j)
        {
            maxLeft[j] = max(nums[j] + j, maxLeft[j - 1]);
            maxRight[n - 1 - j] = max(maxRight[n - j], nums[n - 1 - j] - n + 1 + j);
        }
        for(int j = 1; j < n - 1; ++j)
        {
            if(nums[j] + maxLeft[j - 1] + maxRight[j + 1] > maxSum)
                maxSum = nums[j] + maxLeft[j - 1] + maxRight[j + 1];
        }
        cout << maxSum << endl;
    }
}