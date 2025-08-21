//
// Created by Katie He on 3/18/25.
//

#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int current = 0;
    int power = 1;
    map<int, long long> counts;
    counts[0] = 1;
    for(char c : s)
    {
        int x = c - '0';
        current = (10 * current + x) % 2019;
        power = (power * 202) % 2019;
        ++counts[(current * power) % 2019];
    }
    long long count = 0;
    for(pair<int, long long> i : counts)
    {
        //cout << i.first << " " << i.second << endl;
        count += (i.second) * (i.second - 1) / 2;
    }
    cout << count << endl;
}