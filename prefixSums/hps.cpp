//
// Created by Katie He on 3/16/25.
//

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream read("hps.in");
    ofstream write("hps.out");
    int n;
    read >> n;
    vector<char> order(n);
    for(int i = 0; i < n; ++i)
    {
        char x;
        read >> x;
        order[i] = x;
    }
    vector<int> partial1(n + 1);
    vector<int> partial2(n + 1);
    vector<int> partial3(n + 1);
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    for(int i = 0; i < n; ++i)
    {
        partial1[i + 1] = partial1[i];
        partial2[i + 1] = partial2[i];
        partial3[i + 1] = partial3[i];
        if(order[i] == 'H')
        {
            ++partial1[i + 1];
            ++count1;
        }
        else if(order[i] == 'P')
        {
            ++partial2[i + 1];
            ++count2;
        }
        else if(order[i] == 'S')
        {
            ++partial3[i + 1];
            ++count3;
        }
    }
    int maxPoints = 0;
    for(int i = 1; i < n; ++i)
    {
        int maxFirst = max(partial3[i], max(partial1[i], partial2[i]));
        int maxLast = max(count3 - partial3[i], max(count2 - partial2[i], count1 - partial1[i]));
        if(maxFirst + maxLast > maxPoints)
            maxPoints = maxFirst + maxLast;
    }
    write << maxPoints << endl;
    return 0;
}