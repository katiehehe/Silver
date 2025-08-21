//
// Created by Katie He on 3/18/25.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    set<int> totalLetters;
    vector<vector<int>> partial(26, vector<int>(l + 1));
    for(int i = 1; i <= l; ++i)
    {
        ++partial[s[i - 1] - 'a'][i];
        totalLetters.insert(s[i - 1] - 'a');
    }
    for(int x : totalLetters)
    {
        for(int i = 0; i < l; ++i)
        {
            partial[x][i + 1] = partial[x][i + 1] + partial[x][i];
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int a, b;
        cin >> a >> b;
        if(a == b)
        {
            cout << "Yes" << endl;
            continue;
        }
        if(s[a - 1] != s[b - 1])
        {
            cout << "Yes" << endl;
            continue;
        }
        int count = 0;
        for(int x : totalLetters)
        {
            if(partial[x][b] - partial[x][a - 1] > 0)
                ++count;
        }
        if(count > 2)
        {
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }
}