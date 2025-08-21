//
// Created by Katie He on 6/10/25.
//

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

long long lastTrue(long long low, long long high, function<bool(long long)> f)
{
    --low;
    while(low < high)
    {
        long long mid = (low + high + 1) / 2;
        if(f(mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int n, c, m;
        cin >> n >> c >> m;
        vector<vector<long long>> arr(n, vector<long long>(3));
        for(int j = 0; j < n; ++j)
            cin >> arr[j][0] >> arr[j][1] >> arr[j][2];
        long long x = lastTrue(2, m + c, [&](long long s)
        {
            //cout << "testing sum of " << s << endl;
            long long maxC = c;
            long long maxM = m;
            //cout << maxM << maxC << endl;
            for(int j = 0; j < n; ++j)
            {
                //cout << j << " friend is being tested" << endl;
                long long a = arr[j][0];
                long long b = arr[j][1];
                long long sum = arr[j][2];
                if(a == b)
                {
                    if(sum / a < s)
                        return false;
                }
                else if(a < b)
                {
                    if(sum - a * s <= 0)
                        return false;
                    maxM = min((sum - a * s) / (b - a), maxM);
                }
                else
                {
                    if(sum - b * s <= 0)
                        return false;
                    maxC = min((sum - b * s) / (a - b), maxC);
                }
            }
            //cout << "the max cookie and coffee are " << maxM << " and " << maxC << endl;
            if(maxM > 0 && maxC > 0 && (maxM + maxC >= s))
            {
                //cout << "this does work" << endl;
                return true;
            }
            //cout << "this does not work" << endl;
            return false;
        });
        cout << c + m - x << endl;
    }
}