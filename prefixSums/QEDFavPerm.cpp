//
// Created by Katie He on 5/29/25.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    //cout << t << endl;
    for(int i = 0; i < t; ++i)
    {
        int n, q;
        cin >> n >> q;
        // vector of needed connections
        vector<int> need(n + 2);
        for(int j = 1; j <= n; ++j)
        {
            int loc;
            cin >> loc;
            int a = min(loc, j);
            int b = max(loc, j);
            ++need[a];
            --need[b];
        }
        for(int j = 1; j <= n; ++j)
        {
            need[j] += need[j - 1];
        }
        for(int j = 1; j <= n; ++j)
        {
            need[j] = (need[j] > 0 ? 1 : 0);
        }
        //for(int k : need)
        //    cout << k << " ";
        //cout << endl;
        // string of directions
        string s;
        cin >> s;
        // see if any sections are bad
        unordered_set<int> sections;
        for(int j = 1; j < n - 1; ++j)
        {
            if(need[j] && s[j - 1] == 'L' && s[j] == 'R')
                sections.insert(j);
        }
        // process the queries
        for(int j = 0; j < q; ++j)
        {
            int x;
            cin >> x;
            if(s[x - 1] == 'R')
                s[x - 1] = 'L';
            else
                s[x - 1] = 'R';
            int check = x - 2;
            for(int k = 0; k < 2; ++k)
            {
                if(need[check + 1] && s[check] == 'L' && s[check + 1] == 'R')
                    sections.insert(check + 1);
                else if(sections.count(check + 1) != 0)
                    sections.erase(check + 1);
                ++check;
            }
            //cout << "the bad sections are ";
            //for(int k : sections)
            //    cout << k << " ";
            //cout << endl;
            if(sections.size() == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}