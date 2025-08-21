//
// Created by Katie He on 6/21/25.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

int count(int x, vector<vector<int>>& graph)
{
    if(graph[x].empty())
        return 0;
    int total = graph[x].size();
    for(int i : graph[x])
    {
        total += count(i, graph);
    }
    return total;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> north;
    vector<vector<int>> east;
    for(int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        if(c == 'E')
            east.push_back({i, a, b});
        else
            north.push_back({i, a, b});
    }
    vector<vector<int>> blocks;
    for(int i = 0; i < east.size(); ++i)
    {
        for(int j = 0; j < north.size(); ++j)
        {
            if(east[i][1] < north[j][1] && east[i][2] > north[j][2])
            {
                int eastMeet = north[j][1] - east[i][1];
                int northMeet = east[i][2] - north[j][2];
                if(eastMeet != northMeet)
                {
                    if(eastMeet < northMeet)
                    {
                        blocks.push_back({northMeet, east[i][0], north[j][0], north[j][1] + east[i][2]});
                    }
                    else
                    {
                        blocks.push_back({eastMeet, north[j][0], east[i][0], north[j][1] + east[i][2]});
                    }
                }
            }
        }
    }
    sort(blocks.begin(), blocks.end());
    /*for(auto& x : blocks)
    {
        for(int d : x)
        {
            cout << d << " ";
        }
        cout << endl;
    }*/
    map<int, int> blocked;
    vector<vector<int>> edges(n);
    for(auto& x : blocks)
    {
        if(blocked.count(x[2]) == 0 && (!blocked.count(x[1]) || blocked[x[1]] > x[3]))
        {
            edges[x[1]].push_back(x[2]);
            blocked[x[2]] = x[3];
        }
    }
    /*
    for(auto& x : edges)
    {
        for(int i : x)
            cout << i << " ";
        cout << endl;g
    }
     */
    for(int i = 0; i < n; ++i)
    {
        cout << count(i, edges) << endl;
    }
}