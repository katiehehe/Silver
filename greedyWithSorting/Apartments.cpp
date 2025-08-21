//
// Created by Katie He on 6/23/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ppl(n);
    vector<int> sizes(m);
    for(int i = 0; i < n; ++i)
        cin >> ppl[i];
    for(int i = 0; i < m; ++i)
        cin >> sizes[i];
    sort(ppl.begin(), ppl.end());
    sort(sizes.begin(), sizes.end());
    int person = 0;
    int size = 0;
    int count = 0;
    while(person < n && size < m)
    {
        if(sizes[size] >= ppl[person] - k && sizes[size] <= ppl[person] + k)
        {
            ++count;
            ++person;
            ++size;
        }
        else if(sizes[size] < ppl[person] - k)
        {
            ++size;
        }
        else
        {
            ++person;
        }
    }
    cout << count << endl;
}