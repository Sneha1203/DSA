// WRONG APPROACH !!!
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string printLPSubstring (string s1) {
    string s2 = s1;
    reverse (s1.begin(), s1.end());
    int n = s1.length();
    int dp[n + 1][n + 1];
    int maxLength = INT16_MIN;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = 0;
            }
            if (dp[i][j] > maxLength) {
                maxLength = dp[i][j];
            }
        }
    }
    string ans = "";
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans.push_back (s1[i - 1]);
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    reverse (ans.begin(), ans.end());
    return ans;
}

int main() {
    string str = "eabcb";
    cout << printLPSubstring(str) << endl;
    return 0;
}