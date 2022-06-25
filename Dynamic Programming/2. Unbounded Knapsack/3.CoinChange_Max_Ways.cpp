#include <iostream>
using namespace std;

int maxWays (int coin[], int sum, int size) {
    int dp[size + 1][sum + 1];

    for (int i = 0; i < sum + 1; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i < size + 1; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (coin[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[size][sum];
}

int main() {
    int coin[] = {1, 2, 3};
    int sum = 5;
    cout << endl << maxWays (coin, sum, 3) << endl;
    return 0;
}