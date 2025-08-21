//
// Created by Katie He on 6/25/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    ll sumBoys = 0;
    ll sumGirls = 0;
    vector<ll> boys(n);
    vector<ll> girls(m);
    for(int i = 0; i < n; ++i)
    {
        cin >> boys[i];
        sumBoys += boys[i];
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> girls[i];
        sumGirls += girls[i];
    }
    sort(boys.rbegin(), boys.rend());
    sort(girls.begin(), girls.end());
    if(boys[0] > girls[0])
    {
        cout << -1 << endl;
        return 0;
    }
    ll totalSum = 0;
    if(boys[0] == girls[0])
    {
        cout << sumBoys * m + sumGirls - m * boys[0] << endl;
    }
    else
    {
        cout << sumBoys * m + sumGirls - (m - 1) * boys[0] - boys[1] << endl;
    }
}