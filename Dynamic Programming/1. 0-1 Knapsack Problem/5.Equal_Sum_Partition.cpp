#include <iostream>
using namespace std;

bool isSubset (int arr[], int sum, int size) {
    bool dp[size + 1][sum + 1];

    for (int i = 0; i < size + 1; i++) {
        for (int j = 0; j < sum + 1; j++) {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp [i - 1][j];
            }
        }
    }
    return dp[size][sum];
}

bool equalSumPartition (int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    if (sum % 2 != 0)
        return false;
    else
        return isSubset (arr, sum / 2, size);
}

int main() {
    int arr[] = {1, 5, 5, 11};
    int size = sizeof(arr) / sizeof (int);
    cout << equalSumPartition (arr, size) << endl;
    return 0;
}