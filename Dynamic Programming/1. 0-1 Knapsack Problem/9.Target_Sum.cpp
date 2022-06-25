#include <iostream>
#include <vector>
using namespace std;

int countSubsetSum (int arr[], int sum, int size) {
    int dp[size + 1][sum + 1];
    dp[0][0] = 1;
    for (int i = 0; i < sum + 1; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i < size + 1; i++) {
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

int countSubsetDiff (int arr[], int diff, int size) {
    int sum = 0; 
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    int s1 = (diff + sum) / 2;
    return countSubsetSum (arr, s1, size);
}

int main() {
    int arr[] = {1, 1, 2, 3};
    int diff = 1;
    int size = sizeof(arr) / sizeof(int);
    cout << endl << countSubsetDiff (arr, diff, size) << endl;
    return 0;
}