//
// Created by Katie He on 3/17/25.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        vector<int> partial(n + 1);
        map<int, long long> counts;
        ++counts[0];
        string s;
        cin >> s;
        for(int j = 0; j < n; ++j)
        {
            partial[j + 1] = partial[j] + (s[j] - '0');
            ++counts[partial[j + 1] - (j + 1)];
        }
        long long count = 0;
        for(auto & it : counts)
        {
            count += (it.second) * (it.second - 1) / 2;
        }
        cout << count << endl;
    }
}