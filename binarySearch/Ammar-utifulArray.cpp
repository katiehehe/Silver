//
// Created by Katie He on 6/17/25.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vals(n);
    vector<int> cols(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> vals[i];
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> cols[i];
    }
    map<int, vector<long long>> elems;
    for(int i = 0; i < n; ++i)
    {
        if(elems.count(cols[i]) == 0)
            elems[cols[i]] = {0};
        elems[cols[i]].push_back(elems[cols[i]].back() + vals[i]);
    }
    //for(auto& pair : elems)
    //{
    //    for(int i = 1; i < pair.second.size(); ++i)
    //    {
    //        pair.second[i] += pair.second[i - 1];
    //    }
    //}
    int q;
    cin >> q;
    map<int, long long> added;
    long long totalAdded = 0;
    for(int i = 0; i < q; ++i)
    {
        int a, col;
        long long val;
        cin >> a >> col >> val;
        if(a == 1)
        {
            totalAdded += val;
            added[col] += val;
        }
        else
        {
            int low = 0;
            int high = elems[col].size() - 1;
            while(low < high)
            {
                int mid = low + (high - low + 1) / 2;
                if(elems[col][mid] <= val - mid * (totalAdded - added[col]))
                {
                    low = mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
            cout << low << endl;
        }
    }
}