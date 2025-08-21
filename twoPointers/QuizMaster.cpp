//
// Created by Katie He on 6/5/25.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n, m;
        cin >> n >> m;
        vector<int> studs;
        // map of students
        map<int, unordered_set<int>> divs;
        int maxStud = 0;
        // n log n
        for(int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            maxStud = max(maxStud, x);
            divs[x];
        }
        int index = 0;
        // n
        for (const auto& [key, value] : divs)
        {
            studs.push_back(key);
            ++index;
        }
        // 10^5 (log m)(log n)
        for(int j = 1; j <= m; ++j)
        {
            int mult = 1;
            while (mult * j <= maxStud)
            {
                if(divs.count(mult * j) > 0)
                {
                    divs[mult * j].insert(j);
                    //cout << mult * j << " is found for " << j << endl;
                }
                ++mult;
            }
        }
        //for (const auto& [key, value] : divs)
        //{
            //cout << "the number " << key << " has divisors ";
            //for(int j : value)
            //   cout << j << " ";
            //cout << endl;
        //}
        unordered_map<int, int> currDivs;
        int l = 0;
        int close = INT_MAX;
        for(int r = 0; r < studs.size(); ++r)
        {
           //cout << "exploring " << r << endl;
            for(int div : divs[studs[r]])
                ++currDivs[div];
            while(l + 1 <= r)
            {
                int canRemove = true;
                for(int pot : divs[studs[l]])
                {
                    if(currDivs[pot] < 2)
                        canRemove = false;
                }
                if(canRemove)
                {
                    for(int pot : divs[studs[l]])
                    {
                        --currDivs[pot];
                    }
                    ++l;
                }
                else
                    break;
            }
            //cout << "left ends up at " << l << endl;
            //cout << "the set of divisors is " << endl;
            //for (const auto& [key, value] : currDivs)
            //{
                //cout << "the number " << key << " has " << value << " multiples";
                //cout << endl;
            //}
            if(currDivs.size() == m)
            {
                //cout << "left and right at " << l << " " << r << endl;
                close = min(close, studs[r] - studs[l]);
            }
        }
        if(close == INT_MAX)
            cout << -1 << endl;
        else
            cout << close << endl;
    }
}