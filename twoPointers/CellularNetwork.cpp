//
// Created by Katie He on 6/4/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cities(n);
    vector<int> towers(m);
    vector<int> mins(n, INT_MAX);
    for(int i = 0; i < n; ++i)
        cin >> cities[i];
    for(int i = 0; i < m; ++i)
        cin >> towers[i];
    int tow = 0;
    int cit = 0;
    while(cit < n)
    {
        while(tow + 1 < m && towers[tow + 1] <= cities[cit])
        {
            ++tow;
        }
        //cout << "city index is " << cit << " and tow is at " << tow << endl;
        if(cities[cit] >= towers[tow])
            mins[cit] = cities[cit] - towers[tow];
        ++cit;
    }
    //for(int i : mins)
    //    cout << i << " ";
    //cout << endl;
    int tow2 = m - 1;
    int cit2 = n - 1;
    //cout << endl;
    while(cit2 >= 0)
    {
        while(tow2 - 1 >= 0 && towers[tow2 - 1] >= cities[cit2])
        {
            --tow2;
        }
        //cout << "city index is " << cit2 << " and tow is at " << tow2 << endl;
        if(towers[tow2] >= cities[cit2])
            mins[cit2] = min(mins[cit2], towers[tow2] - cities[cit2]);
        --cit2;
    }
    //for(int i : mins)
    //    cout << i << " ";
    //cout << endl;
    int max1 = 0;
    for(int i : mins)
    {
        max1 = max(i, max1);
    }
    cout << max1 << endl;
}