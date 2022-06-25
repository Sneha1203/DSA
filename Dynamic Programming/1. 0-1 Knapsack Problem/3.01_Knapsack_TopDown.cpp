#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int maxProfit (int wt[], int val[], int W, int n) {
    int profit [n + 1][W + 1];
    
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            if (i == 0 || j == 0) {
                profit[i][j] = 0;
            }

            else if (wt[i - 1] <= j) {
                profit[i][j] = max (val [i - 1] + profit[i - 1][j - wt[i - 1]], profit[i - 1][j]);
            } 
            
            else {
                profit[i][j] = profit[i - 1][j];
            }
        }
    }
    return profit[n][W];
}

int main() {
    int wt[] = {1,3,4,5};
    int val[] = {1, 4, 5, 7};
    int W = 10;
    int n = 4;
    cout << maxProfit (wt, val, W, n) << endl;
    return 0;
}