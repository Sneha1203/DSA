#include <iostream>
using namespace std;

// int gridTravellerREC (int n, int m) {
//     if (n == 1 && m == 1)
//         return 1;
//     if (n == 0 || m == 0)
//         return 0;
//     return gridTravellerREC(n - 1, m) + gridTravellerREC (n, m - 1);
// }

int gridTraveller (int n, int m) {
    int dp[n + 1][m + 1] = {0};

    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < m + 1; i++) {
        dp[0][i] = 0;
    }
    // dp[1][1] = 1;

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (i == 1 && j == 1)
                dp[i][j] = 1;
            else 
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    return dp[n][m];
}

int main() {
    // cout << gridTravellerREC (3, 3) << endl;
    cout << gridTraveller (3, 3) << endl;
    // gridTraveller(3,3);
    return 0;
}