//
// Created by Katie He on 3/16/25.
//

#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream read("div7.in");
    ofstream write("div7.out");
    int n;
    read >> n;
    vector<int> cows(n + 1);
    for(int i = 0; i < n; ++i)
    {
        int x;
        read >> x;
        x = x % 7;
        cows[i + 1] = cows[i] + x;
    }
    for(int i = n; i > 0; --i)
    {
        for(int j = 0; j < n - i + 1; ++j)
        {
            if((cows[j + i] - cows[j]) % 7 == 0)
            {
                write << i << endl;
                return 0;
            }
        }
    }
    write << 0 << endl;
    return 0;
}