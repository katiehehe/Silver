//
// Created by Katie He on 6/2/25.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int l = 0;
    int r = -1;
    int sum = 0;
    int maxLength = 0;
    while(l < n)
    {
        //cout << "left is at " << l << endl;
        while(r < n - 1 && sum + arr[r + 1] <= t)
        {
            sum += arr[r + 1];
            ++r;
        }
        //cout << "r ends up at " << r << endl;
        maxLength = max(maxLength, r - l + 1);
        ++l;
        if(r < l)
        {
            r = l - 1;
            sum = 0;
        }
        else
            sum -= arr[l - 1];
        //cout << "sum is now " << sum << " and r is at " << r << endl;
        //cout << endl;
    }
    cout << maxLength << endl;
}