//
// Created by Katie He on 3/17/25.
//

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> partial(n + 1);
    vector<int> mods(n);
    mods[0] = 1;
    int partialSum = 0;
    ll count = 0;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        partialSum = ((partialSum + x) % n + n) % n;
        count += mods[partialSum];
        ++mods[partialSum];
    }
    cout << count << endl;
}