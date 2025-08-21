//
// Created by Katie He on 5/15/25.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> coords(n, vector<int>(2));
    for(int i = 0; i < n; ++i)
    {
        cin >> coords[i][0];
        cin >> coords[i][1];
    }
    // sort based on y-coord
    sort(coords.begin(), coords.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    map<int, int> yCoord;
    for(int i = 0; i < n; ++i)
    {
        yCoord[coords[i][1]] = i;
    }
    // sort based on x-coord
    sort(coords.begin(), coords.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
    for(int i = 0; i < n; ++i)
    {
        coords[i][0] = i;
        coords[i][1] = yCoord[coords[i][1]];
    }
    // find the partial sums
    vector<vector<int>> abovePartial(n + 1, vector<int>(n));
    vector<vector<int>> belowPartial(n + 1, vector<int>(n));
    for(int y = 0; y < n; ++y)
    {
        for(int x = 1; x < n + 1; ++x)
        {
            abovePartial[x][y] = abovePartial[x - 1][y] + (coords[x - 1][1] > y);
            belowPartial[x][y] = belowPartial[x - 1][y] + (coords[x - 1][1] < y);
        }
    }
    // calculate the total
    long long total = n + 1;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            int highY = max(coords[i][1], coords[j][1]);
            int lowY = min(coords[i][1], coords[j][1]);
            int below = belowPartial[j + 1][lowY] - belowPartial[i][lowY] + 1;
            int above = abovePartial[j + 1][highY] - abovePartial[i][highY] + 1;
            total += (long)(below) * above;
        }
    }
    cout << total << endl;
    return 0;
}