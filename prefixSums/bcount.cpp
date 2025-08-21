//
// Created by Katie He on 3/16/25.
//

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int a, b, c;
    Node(int a, int b, int c) : a(a), b(b), c(c){}
    Node() {a = 0; b = 0; c = 0;}
};

int main()
{
    ifstream read("bcount.in");
    ofstream write("bcount.out");
    if (!read.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;  // Exit with an error code
    }

    int n, q;
    read >> n >> q;
    vector<Node> cows(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        int x;
        read >> x;
        if(x == 1)
        {
            cows[i] = Node(cows[i - 1].a + 1, cows[i - 1].b, cows[i - 1].c);
        }
        else if(x == 2)
        {
            cows[i] = Node(cows[i - 1].a, cows[i - 1].b + 1, cows[i - 1].c);
        }
        else if(x == 3)
        {
            cows[i] = Node(cows[i - 1].a, cows[i - 1].b, cows[i - 1].c + 1);
        }
    }
    for(int i = 0; i < q; ++i)
    {
        int l, r;
        read >> l >> r;
        write << cows[r].a - cows[l - 1].a << " " << cows[r].b - cows[l - 1].b << " " << cows[r].c - cows[l - 1].c << endl;
    }
}