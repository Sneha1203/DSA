#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int lengthLCS (string x, string y, int n, int m) {
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            if (i == 0 || j == 0) {
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

int minIns (string x, string y) {
    int n = x.length();
    int m = y.length();
    int lcs = lengthLCS (x, y, n, m);
    return m - lcs;
}

int minDel (string x, string y) {
    int n = x.length();
    int m = y.length();
    int lcs = lengthLCS (x, y, n, m);
    return n - lcs;
}

int main() {
    string x = "heap";
    string y = "pea";
    cout << "MIN INS: " << minIns (x, y) << endl;
    cout << "MIN DEL: " << minDel (x, y) << endl;
    return 0;
}