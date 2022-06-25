#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCS (string x, string y) {
    int n = x.length();
    int m = y.length();
    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            } else if (x[i - 1] == y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

bool seqPatternMatching (string x, string y) {
    int n = x.length();
    int lcs = LCS (x, y);
    if (lcs == n)
        return true;
    else
        return false;
}

int main() {
    string x = "AXY";
    string y = "ADXCPY";
    cout << seqPatternMatching (x, y) << endl;
    return 0;
}