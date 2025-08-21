//
// Created by Katie He on 6/11/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m, q;
    cin >> n >> m >> q;
    long long a = 0;
    for(long long i = 0; i < n; ++i)
    {
        long long x;
        cin >> x;
        if(i % 2 == 0)
            a += x;
        else
            a -= x;
    }
    //cout << a << endl;
    long long currSum = 0;
    vector<long long> bTemp(m);
    vector<long long> b;
    for(long long i = 0; i < n; ++i)
    {
        long long x;
        cin >> x;
        bTemp[i] = x;
        if(i % 2 == 0)
            currSum += x;
        else
            currSum -= x;
    }
    b.push_back(currSum);
    for(long long i = n; i < m; ++i)
    {
        long long x;
        cin >> x;
        bTemp[i] = x;
        if(n % 2 == 1)
            currSum = -(currSum - bTemp[i - n]) + bTemp[i];
        else
            currSum = -(currSum - bTemp[i - n]) - bTemp[i];
        b.push_back(currSum);
    }
    //cout << endl;
    //for(long long i : bTemp)
    //    cout << i << " ";
    //cout << endl;
    sort(b.begin(), b.end());
    //for(long long i : b)
    //    cout << i << " ";
    vector<long long>::iterator it = lower_bound(b.begin(), b.end(), a);
    long long diff = 0;
    if(it == b.end())
        diff = llabs(*(it - 1) - a);
    else if(it == b.begin())
        diff = llabs(*it - a);
    else
        diff = min(llabs(*it - a), llabs(*(it - 1) - a));
    //cout << endl;
    cout << diff << endl;
    for(long long i = 0; i < q; ++i)
    {
        long long l, r, x;
        cin >> l >> r >> x;
        //cout << l << " " << r << " " << x << endl;
        if((r - l + 1) % 2 == 0)
        {
            //cout << "first option" << endl;
            cout << diff << endl;
        }
        else
        {
            //cout << "second option" << endl;
            if(l % 2 == 1)
                a += x;
            else
                a -= x;
            //cout << a << " is what a ends up as" << endl;
            it = lower_bound(b.begin(), b.end(), a);
            if(it == b.end())
                diff = llabs(*(it - 1) - a);
            else if(it == b.begin())
                diff = llabs(*it - a);
            else
                diff = min(llabs(*it - a), llabs(*(it - 1) - a));
            cout << diff << endl;
        }
    }
}