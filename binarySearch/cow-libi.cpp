//
// Created by Katie He on 6/7/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b)
{
    return a[0] < b[0];
}

int main()
{
    int g, n;
    cin >> g >> n;
    vector<vector<int>> grazings(g, vector<int>(3));
    for(int i = 0; i < g; ++i)
    {
        cin >> grazings[i][1] >> grazings[i][2] >> grazings[i][0];
    }
    sort(grazings.begin(), grazings.end(), compare);
    int count = 0;
    for(int i = 0; i < n; ++i)
    {
        bool yes = 0;
        int x, y, t;
        cin >> x >> y >> t;
        vector<int> target = {t, 0, 0};
        vector<vector<int>>::iterator low = lower_bound(grazings.begin(), grazings.end(), target, compare);
        vector<vector<int>>::iterator high = upper_bound(grazings.begin(), grazings.end(), target, compare) - 1;
        if(low >= grazings.begin() && low < grazings.end())
        {
            long long dist = (long long)((*low)[1] - x) * ((*low)[1] - x) + (long long)((*low)[2] - y) * ((*low)[2] - y);
            long long time = (long long)((*low)[0] - t) * ((*low)[0] - t);
            if(dist > time)
                yes = 1;
        }
        if(!yes && high >= grazings.begin() && high < grazings.end())
        {
            long long dist = (long long)((*high)[1] - x) * ((*high)[1] - x) + (long long)((*high)[2] - y) * ((*high)[2] - y);
            long long time = (long long)((*high)[0] - t) * ((*high)[0] - t);
            if(dist > time)
                yes = 1;
        }
        if(yes)
        {
            //cout << i << endl;
            ++count;
        }
    }
    cout << count << endl;
}