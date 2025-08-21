//
// Created by Katie He on 6/13/25.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr;
    int x1;
    cin >> x1;
    arr.push_back({x1});
    for(int i = 1; i < n; ++i)
    {
        int x;
        cin >> x;
        int low = 0;
        int high = arr.size();
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(arr[mid][arr[mid].size() - 1] <= x)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        if(high == arr.size())
        {
            arr.push_back({x});
        }
        else
        {
            arr[high].push_back(x);
        }
    }
    for(int i = 0; i < arr.size(); ++i)
    {
        for(int j : arr[i])
            cout << j << " ";
        cout << endl;
    }
}