#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int t[1000][1000];

int maxProfit (int wt[], int val[], int W, int n) {
    if (W == 0 || n == 0) {
        return 0;
    }
    if (t[W][n] != -1) {
        return t[W][n];
    }

    if (wt[ n - 1] <= W) {
        t[W][n] = max ((val [n - 1] + maxProfit (wt, val, W - wt[n - 1], n - 1)), maxProfit (wt, val, W, n - 1));
        return t[W][n];
    } else {
        t[W][n] = maxProfit (wt, val, W, n - 1);
        return t[W][n];
    }
}

int main() {
    memset (t, -1, sizeof (t));
    int wt[] = {1,3,4,5};
    int val[] = {1, 4, 5, 7};
    int W = 10;
    int n = 4;
    cout << maxProfit (wt, val, W, n) << endl;
    return 0;
}