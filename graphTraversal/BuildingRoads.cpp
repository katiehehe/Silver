#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, vector<bool>& visited, vector<int> adj[])
{
    visited[x] = true;
    for (int i : adj[x])
        if (!visited[i])
            dfs(i, visited, adj);
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> adj[m];
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    vector<bool> visited(m, false);
    vector<int> vertices;
    for (int i = 0; i < m; ++i)
    {
        if (visited[i]) continue;
        vertices.push_back(i);
        dfs(i, visited, adj);
    }

    cout << vertices.size() - 1 << endl;
    for (int i = 0; i + 1 < (int)vertices.size(); ++i)
        cout << vertices[i] + 1 << " " << vertices[i + 1] + 1 << endl;
}
