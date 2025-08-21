//
// Created by Katie He on 7/14/25.
//

#include <iostream>
#include <vector>
using namespace std;

bool dfs(int col, int x, vector<vector<int>>& adj, vector<int>& colors)
{
    //cout << "at vert " << x << endl;
    for(int i : adj[x])
    {
        if(colors[i] == col)
            return false;
    }
    colors[x] = col;
    for(int i : adj[x])
    {
        if(colors[i] == -1)
            if(!dfs((col + 1) % 2, i, adj, colors))
                return false;
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    vector<int> colors(n, -1);
    for(int i = 0; i < n; ++i)
    {
        if(colors[i] == -1)
        {
            if(!dfs(0, i, adj, colors))
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    for(int i : colors)
        cout << i + 1 << " ";
    cout << endl;
}