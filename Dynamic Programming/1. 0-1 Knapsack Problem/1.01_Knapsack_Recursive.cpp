#include <bits/stdc++.h>
using namespace std;

int maxProfit (int wt[], int val[], int W, int n) {
    if (n == 0 || W == 0) {
        return 0;
    }

    if (wt[n - 1] <= W) {
        return max ((val [n - 1] + maxProfit (wt, val, W - wt[n - 1], n - 1)) , maxProfit (wt, val, W, n - 1));
    } else {
        return maxProfit (wt, val, W, n - 1);
    }
}

int main() {
    int wt[] = {1,3,4,5};
    int val[] = {1, 4, 5, 7};
    int W = 10;
    int n = 4;
    cout << maxProfit (wt, val, W, n) << endl;
    return 0;
}