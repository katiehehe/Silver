//
// Created by Katie He on 5/25/25.
//

#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    // initial array
    vector<ll> arr(n + 1);
    for(int i = 1; i < n + 1; ++i)
    {
        cin >> arr[i];
    }
    // set up the operations
    vector<vector<int>> ops(m + 1, vector<int>(3));
    for(int i = 1; i < m + 1; ++i)
    {
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    }
    // frequencies of operations
    vector<ll> cum(m + 2);
    for(int i = 0; i < k; ++i)
    {
        int l, r;
        cin >> l >> r;
        ++cum[l];
        --cum[r + 1];
    }
    for(int i = 1; i < m + 1; ++i)
    {
        cum[i] += cum[i - 1];
    }
    // set up the real differences based on op frequencies
    vector<ll> differences(n + 2);
    for(int i = 1; i < m + 1; ++i)
    {
        differences[ops[i][0]] += cum[i] * ops[i][2];
        differences[ops[i][1] + 1] -= cum[i] * ops[i][2];
    }
    for(int i = 1; i < n + 1; ++i)
    {
        differences[i] += differences[i - 1];
    }
    for(int i = 1; i < n + 1; ++i)
    {
        cout << arr[i] + differences[i] << " ";
    }
    return 0;
}