#include <iostream>
using namespace std;

int lcsTopDown (string x, string y, int n, int m) {
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

int main() {
    string x, y;
    int n, m;
    cout << "Enter string 1: ";
    cin >> x;
    cout << "Enter string 2: ";
    cin >> y;
    n = x.length();
    m = y.length();
    cout << endl << lcsTopDown(x, y, n, m) << endl;
    return 0;
}