//
// Created by Katie He on 6/21/25.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using ll = long long;
using namespace std;

ll minArea(vector<vector<ll>>& cows)
{
    vector<vector<ll>> xCoords;
    int cow = 0;
    while(cow < cows.size())
    {
        ll minY = cows[cow][1];
        ll maxY = minY;
        //cout << minY << endl;
        while(cow + 1 < cows.size() && cows[cow][0] == cows[cow + 1][0])
        {
            ++cow;
            minY = min(minY, cows[cow][1]);
            maxY = max(maxY, cows[cow][1]);
        }
        //cout << minY << " " << maxY << endl;
        //cout << endl;
        xCoords.push_back({cows[cow][0], minY, maxY});
        ++cow;
    }
    if(xCoords.size() == 1)
        return 0;
    vector<vector<ll>> xCoordsBack = xCoords;
    for(int i = 1; i < xCoords.size(); ++i)
    {
        xCoords[i][1] = min(xCoords[i - 1][1], xCoords[i][1]);
        xCoords[i][2] = max(xCoords[i - 1][2], xCoords[i][2]);
    }

    /*
    for(auto& i : xCoords)
    {
        for(int k : i)
            cout << k << " ";
        cout << endl;
    }
    cout << endl;
    */

    for(int i = xCoordsBack.size() - 2; i >= 0; --i)
    {
        xCoordsBack[i][1] = min(xCoordsBack[i + 1][1], xCoordsBack[i][1]);
        xCoordsBack[i][2] = max(xCoordsBack[i + 1][2], xCoordsBack[i][2]);
    }

    /*
    for(auto& i : xCoordsBack)
    {
        for(int k : i)
            cout << k << " ";
        cout << endl;
    }
    cout << endl;
     */

    ll minA = 1e18;
    for(int i = 0; i < xCoords.size() - 1; ++i)
    {
        minA = min(minA, (xCoords[i][0] - xCoords[0][0]) * (xCoords[i][2] - xCoords[i][1]) +
        ((xCoordsBack.back())[0] - xCoordsBack[i + 1][0]) * (xCoordsBack[i + 1][2] - xCoordsBack[i + 1][1]));
    }
    //cout << minA << endl;
    return minA;
}

int main()
{
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<ll>> cowsX(n, vector<ll>(2));
    vector<vector<ll>> cowsY(n, vector<ll>(2));
    for(int i = 0; i < n; ++i)
    {
        cin >> cowsX[i][0] >> cowsX[i][1];
        cowsY[i][0] = cowsX[i][1];
        cowsY[i][1] = cowsX[i][0];
    }
    sort(cowsX.begin(), cowsX.end());
    sort(cowsY.begin(), cowsY.end());
    ll xDiff = cowsX[n - 1][0] - cowsX[0][0];
    ll yDiff = cowsY[n - 1][0] - cowsY[0][0];
    cout << (xDiff * yDiff) - min(minArea(cowsX), minArea(cowsY));
}