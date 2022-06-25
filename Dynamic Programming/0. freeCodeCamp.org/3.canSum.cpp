#include <iostream>
using namespace std;

// bool canSumREC (int target, int arr[], int size) {
//     if (target == 0)
//         return true;
//     if (target < 0)
//         return false;
//     for (int i = 0; i < size; i++) {
//         int rem = target - arr[i];
//         if (canSumREC (rem, arr, size))
//             return true;
//     }
//     return false;
// }

bool canSum (int target, int arr[], int size) {
    int dp[size + 1][target + 1];

    for (int i = 0; i < target + 1; i++) {
        dp[0][i] = false;
    }

    for (int i = 0; i <  size + 1; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < target + 1; j++) {
            if (arr[i - 1] < target) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[size][target];
}
int main() {
    int arr[] ={2, 3, 7, 8, 10};
    cout << canSum (11,arr, 5) << endl;
    return 0;
}