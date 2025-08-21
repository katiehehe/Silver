//
// Created by Katie He on 5/25/25.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    int max = 200000;
    vector<int> temps(max + 2);
    for(int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        ++temps[l];
        --temps[r + 1];
    }
    for(int i = 1; i < max + 1; ++i)
    {
        temps[i] += temps[i - 1];
    }
    for(int i = 1; i < max + 1; ++i)
    {
        temps[i] = temps[i] >= k;
        temps[i] += temps[i - 1];
    }
    for(int i = 0; i < q; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << temps[b] - temps[a - 1] << endl;
    }
    return 0;
}