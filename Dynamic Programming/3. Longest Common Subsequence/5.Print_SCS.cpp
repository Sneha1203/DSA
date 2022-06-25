#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
string printSCS (string x, string y, int n, int m) {
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

    string scs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            scs.push_back (x[i - 1]);
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                scs.push_back (x[i - 1]);
                i--;
            } else {
                scs.push_back (y[j - 1]);
                j--;
            }
        }
    }
    reverse (scs.begin(), scs.end());
    return scs;
}

int main() {
    string x = "acbcf";
    string y = "abcdaf";
    int n = x.length();
    int m = y.length();
    cout << printSCS (x, y, n, m) << endl;
    return 0;
}