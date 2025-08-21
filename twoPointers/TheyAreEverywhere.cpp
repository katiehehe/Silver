//
// Created by Katie He on 6/4/25.
//

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool valid(unordered_map<char, int>& map)
{
    //cout << "being called" << endl;
    for(auto pair : map)
    {
        //cout << "the first elem is " << pair.first << " and the second is " << pair.second << endl;
        if(pair.second <= 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_set<char> letters;
    for(char c : s)
        letters.insert(c);
    unordered_map<char, int> count;
    //for(char c : letters)
    //    cout << c << endl;
    for(char c : letters)
        count[c];
    int l = 0;
    int r = 0;
    int min1 = INT_MAX;
    while(l < n)
    {
        //cout << "left is at " << l << endl;
        while(r < n && !valid(count))
        {
            count[s[r]]++;
            ++r;
        }
        //cout << "right ends up at " << r << endl;
        if(valid(count))
        {
            min1 = min(min1, r - l);
            //cout << "left is " << l << " and right is " << r << endl;
        }
        --count[s[l]];
        ++l;
    }
    cout << min1 << endl;
}