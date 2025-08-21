//
// Created by Katie He on 6/28/25.
//

#include <iostream>
#include <set>
#include <map>
#include <queue>
#define inf 1000000007
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        set<int> start;
        map<int, vector<int>> list;
        for(int j = 0; j < n; ++j)
        {
            int a, b;
            cin >> a >> b;
            start.insert(a);
            list[a].push_back(b);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        start.insert(inf);
        bool good = true;
        int k = *(start.begin());
        while(k <= 1e9)
        {
            for(auto& e : list[k])
                pq.push(e);
            pq.pop();
            if(pq.empty())
            {
                k = *(start.lower_bound(k + 1));
            }
            else
            {
                if(pq.top() == k){good = false; break;}
                ++k;
            }
        }
        if(good)cout << "Yes" << endl; else cout << "No" << endl;
    }
}