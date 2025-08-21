//
// Created by Katie He on 6/3/25.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    int l = 0;
    int r = 0;
    int sum = 0;
    int count = 0;
    while(l < n)
    {
        while(r < n && sum + arr[r] <= x)
            sum += arr[r++];
        if(sum == x)
            ++count;
        sum -= arr[l++];
    }
    cout << count << endl;
}