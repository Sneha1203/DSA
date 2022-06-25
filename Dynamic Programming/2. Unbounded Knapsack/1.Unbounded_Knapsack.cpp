#include <iostream>
using namespace std;

int unboundedKnapsack (int wt[], int val[], int W, int size) {
    int dp[size + 1][W + 1];
        
        for (int i = 0; i < size + 1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < W + 1; i++) {
            dp[0][i] = 0;
        }
        
        for (int i = 1; i < size + 1; i++) {
            for (int j = 1; j < W + 1; j++) {
                if (wt[i - 1] <= j) {
                    dp[i][j] = max (dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[size][W];
}

int main() {
    int wt[] = {1, 2, 5};
    int val[] = {1, 2, 5};
    int W = 6;
    int size = 3;
    cout << unboundedKnapsack (wt, val, W, size) << endl;
    return 0;
}