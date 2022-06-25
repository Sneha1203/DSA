#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001][1001];

int minMultiplicationMemoized (int arr[], int i, int j) {
    if (i >= j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int minMultiplications = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        int tempans = minMultiplicationMemoized(arr, i, k) + minMultiplicationMemoized (arr, k + 1, j) + arr[i - 1] * arr[j] * arr[k];
        if (tempans < minMultiplications) {
            minMultiplications = tempans;
        }
    }
    return dp[i][j] = minMultiplications;
}

int main() {
    memset (dp, -1, sizeof (dp));
    int arr[] = {40, 20, 30, 10, 30};
    int i = 1;
    int j = (sizeof(arr) / sizeof(int)) - 1;
    cout << minMultiplicationMemoized (arr, i, j) << endl;
    return 0;
}