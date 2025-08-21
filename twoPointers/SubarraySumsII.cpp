//
// Created by Katie He on 3/16/25.
//

#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main()
{
    map<ll, int> counts;
    int n, x;
    cin >> n >> x;
    ll partialSum = 0;
    counts[0] = 1;
    ll count = 0;
    for(int i = 0; i < n; ++i)
    {
        int more;
        cin >> more;
        partialSum += more;
        if(counts.find(partialSum - x) != counts.end())
        {
            count += counts[partialSum - x];
        }
        ++counts[partialSum];
    }
    cout << count << endl;
    return 0;
}