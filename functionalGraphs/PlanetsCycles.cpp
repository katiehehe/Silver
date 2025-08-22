//
// Created by Katie He on 8/21/25.
//

#include <vector>
#include <iostream>
using namespace std;
vector<int> temp;
vector<int> ans;
vector<int> adj;
int length = 0;
bool inCycle = false;

void dfs(int x)
{
    if(ans[x] != -1)
    {
        return;
    }
    if(temp[x] != -2)
    {
        int k = temp[x];
        ans[x] = length - k;
        inCycle = true;
        return;
    }
    temp[x] = length;
    ++length;
    dfs(adj[x]);
    if(ans[x] != -1)
    {
        inCycle = false;
    }
    else
    {
        if(inCycle)
        {
            ans[x] = ans[adj[x]];
        }
        else
        {
            ans[x] = ans[adj[x]] + 1;
        }
    }
    temp[x] = -2;
}

int main()
{
    int n;
    cin >> n;
    temp.resize(n, -2);
    adj.resize(n);
    ans.resize(n, -1);
    for(int i = 0; i < n; ++i)
    {
        cin >> adj[i];
        --adj[i];
    }
    for(int i = 0; i < n; ++i)
    {
        if(ans[i] == -1)
        {
            length = 0;
            dfs(i);
            /*
            cout << "called on " << i << endl;
            for(int j = 0; j < n; ++j)
            {
                cout << ans[j] << " \n"[j == n - 1];
            }
            cout << endl;
            */
        }
    }
    for(int i = 0; i < n; ++i)
    {
        cout << ans[i] << " \n"[i == n - 1];
    }
}