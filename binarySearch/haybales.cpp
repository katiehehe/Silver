//
// Created by Katie He on 6/7/25.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < Q; ++i)
    {
        int a, b;
        cin >> a >> b;
        vector<int>::iterator low, up;
        if((a < arr[0] && b < arr[0]) || (a > arr[N - 1] && b > arr[N - 1]))
        {
            cout << "0" << endl;
            continue;
        }
        low = lower_bound(arr.begin(), arr.end(), a);
        up = upper_bound(arr.begin(), arr.end(), b);
        cout << up - low << endl;
    }
}