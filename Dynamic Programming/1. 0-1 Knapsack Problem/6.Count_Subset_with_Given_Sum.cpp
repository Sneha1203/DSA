#include <iostream>
using namespace std;

int countSubsetSum (int arr[], int sum, int size) {
    int dp[size + 1][sum + 1];
    dp[0][0] = 1;

    for (int i = 1; i < sum + 1; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i < size + 1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[size][sum];
}

int main() {
    int arr[] = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    int size = 6;
    cout << endl << countSubsetSum (arr, sum, size) << endl;
    return 0;
}