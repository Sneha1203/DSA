#include <iostream>
using namespace std;

bool isSubset (int arr[], int sum, int size) {
    bool dp[size + 1][sum + 1];

    for (int i = 0; i < size + 1; i++) {
        for (int j = 0; j < sum + 1; j++) {
            if (i == 0) {
                dp[i][j] = false;
            }
            if (j == 0) {
                dp[i][j] = true;
            }
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[size][sum];
}

int main() {
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;
    int size = sizeof(arr) / sizeof(int) ;
    cout << endl << isSubset (arr, sum, size) << endl;
    return 0;
}