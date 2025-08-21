//
// Created by Katie He on 6/6/25.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int m;
        char c;
        cin >> m >> c;
        int r = 0;
        int max1 = 0;
        for(int l = 0; l < n; ++l)
        {
            while(r < n && m > 0)
            {
                if(s[r] != c)
                    --m;
                ++r;
            }
            while(r < n && s[r] == c)
            {
                ++r;
            }
            max1 = max(max1, r - l);
            if(s[l] != c)
                ++m;
        }
        cout << max1 << endl;
    }
}