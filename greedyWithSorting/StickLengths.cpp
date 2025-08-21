//
// Created by Katie He on 6/23/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> lengths(n);
    for(int i = 0; i < n; ++i)
        cin >> lengths[i];
    sort(lengths.begin(), lengths.end());
    int median = lengths[n / 2];
    long long total = 0;
    for(int i : lengths)
        total += llabs(i - median);
    cout << total << endl;
}
