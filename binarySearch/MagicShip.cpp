//
// Created by Katie He on 6/17/25.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> moves(n + 1, vector<int>(2));
    for(int i = 0; i < n; ++i)
    {
        moves[i + 1][0] = moves[i][0];
        moves[i + 1][1] = moves[i][1];
        if(s[i] == 'U')
        {
            ++moves[i + 1][1];
        }
        else if(s[i] == 'D')
        {
            --moves[i + 1][1];
        }
        else if(s[i] == 'L')
        {
            --moves[i + 1][0];
        }
        else if(s[i] == 'R')
        {
            ++moves[i + 1][0];
        }
    }
    ll low = 0;
    ll high = 1e15;
    while(low < high)
    {
        ll mid = low + (high - low) / 2;
        ll cycle = mid / n;
        ll remainder = mid % n;
        if(llabs(x2 - (x1 + cycle * moves[n][0] + moves[remainder][0])) + llabs(y2 - (y1 + cycle * moves[n][1] + moves[remainder][1])) <= mid)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    if(high == 1e15)
        cout << -1 << endl;
    else
        cout << high << endl;
}