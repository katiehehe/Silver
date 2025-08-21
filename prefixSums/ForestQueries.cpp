//
// Created by Katie He on 3/19/25.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> tree(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        for(int j = 1; j <= n; ++j)
        {
            tree[i][j] = tree[i - 1][j] + tree[i][j - 1] - tree[i - 1][j - 1];
            if(s[j - 1] == '*')
                ++tree[i][j];
        }
    }
    for(int i = 0; i < q; ++i)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << tree[y2][x2] - tree[y2][x1 - 1] - tree[y1 - 1][x2] + tree[y1 - 1][x1 - 1] << endl;
    }
}