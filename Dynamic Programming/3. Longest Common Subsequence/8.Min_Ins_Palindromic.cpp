#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int LPS (string str1) {
    int n = str1.length();
    string str2 = str1;
    reverse (str1.begin(), str1.end());
    int dp[n + 1][n + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j ] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int minIns (string str1) {
    int n = str1.length();
    int lps = LPS (str1);
    return n - lps;
}

int main() {
    string str = "agbcba";
    cout << minIns (str) << endl;
    return 0;
}