//
// Created by Katie He on 3/17/25.
//

#include <fstream>
#include <vector>
using namespace std;

int main()
{
    int n, k, b;
    ifstream read("maxcross.in");
    ofstream write("maxcross.out");
    read >> n >> k >> b;
    vector<int> partial(n + 1);
    for(int i = 0; i < b; ++i)
    {
        int x;
        read >> x;
        partial[x] = 1;
    }
    for(int i = 0; i < n; ++i)
    {
        partial[i + 1] = partial[i] + (partial[i + 1] ? 1 : 0);
    }
    int min = n;
    for(int i = 0; i < n - k + 1; ++i)
    {
        if(partial[i + k] - partial[i] < min)
            min = partial[i + k] - partial[i];
    }
    write << min << endl;
}