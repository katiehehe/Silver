//
// Created by Katie He on 6/24/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int begin = 0;
    int end = n - 1;
    int total = 0;
    while(begin < end)
    {
        ++total;
        if(arr[begin] + arr[end] <= x)
        {
            ++begin;
            --end;
        }
        else
        {
            --end;
        }
    }
    if(begin == end)
    {
        ++total;
    }
    cout << total << endl;
}