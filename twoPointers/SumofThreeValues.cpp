//
// Created by Katie He on 6/3/25.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    map<int, set<int>> elemToIndex;
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        elemToIndex[arr[i]].insert(i);
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n - 2; ++i)
    {
        //cout << "first index is " << i << endl;
        int desSum = x - arr[i];
        int l = i + 1;
        int r = n - 1;
        int currSum = arr[l] + arr[r];
        while(l < r)
        {
            if(currSum < desSum)
                ++l;
            else if(currSum > desSum)
                --r;
            else
            {
                i = arr[i];
                l = arr[l];
                r = arr[r];
                //cout << i << l << r;
                cout << *elemToIndex[i].begin() + 1 << " ";
                elemToIndex[i].erase(elemToIndex[i].begin());
                cout << *elemToIndex[l].begin() + 1 << " ";
                elemToIndex[l].erase(elemToIndex[l].begin());
                cout << *elemToIndex[r].begin() + 1 << endl;
                elemToIndex[r].erase(elemToIndex[r].begin());
                return 0;
            }
            currSum = arr[l] + arr[r];
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}