//
// Created by Katie He on 6/11/25.
//

#include <iostream>
using namespace std;

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();  // Flush so the judge sees the output
    int result;
    cin >> result; // Read the number of ones in [l, r]
    return result;
}

int main() {
    int n, t;
    cin >> n >> t; // number of elements and number of queries
    for (int i = 0; i < t; ++i) {
        int k;
        cin >> k;

        int lo = 1, hi = n;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int ones = ask(1, mid);
            int zeros = mid - ones;
            if (zeros >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        cout << "! " << lo << endl;
        cout.flush();  // Also flush final output
    }
}
