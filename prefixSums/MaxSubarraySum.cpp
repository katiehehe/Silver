//
// Created by Katie He on 3/19/25.
//

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long prefix = 0;
    long long minPrefix = 0;
    long long maxValue = INT_MIN;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        prefix += x;
        if(prefix - minPrefix > maxValue)
            maxValue = prefix - minPrefix;
        if(prefix < minPrefix)
            minPrefix = prefix;
    }
    cout << maxValue << endl;
}