//
// Created by Katie He on 6/11/25.
//

#include <iostream>
using ll = long long;
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll low = 1;
    ll high = n * n;
    while(low <= high) {
        ll mid = (low + high) / 2;
        ll strict = 0;
        ll notStrict = 0;
        for (int i = 1; i <= n; ++i)
        {
            notStrict += min(n, mid / i);
            strict += min(n, (mid - 1) / i);
        }
        if(notStrict >= (n * n + 1) / 2 && strict <= (n * n - 1) / 2)
        {
            //cout << strict << " and " << notStrict << endl;
            cout << mid << endl;
            return 0;
        }
        else if(strict >= (n * n + 1) / 2)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}