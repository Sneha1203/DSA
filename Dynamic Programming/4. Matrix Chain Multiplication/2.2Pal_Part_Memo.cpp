#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int dp[1001][1001];

bool ispalindrome (string str) {
    string checkstr = str;
    reverse (checkstr.begin(), checkstr.end());
    if (str == checkstr) {
        return true;
    } else {
        return false;
    }
}

int minPartitions (string str, int i, int j) {
    if (i >= j)
        return 0;
    if (ispalindrome (str))
        return 0;
    if (dp[i][j] != -1) 
        return dp[i][j];

    int ans = INT_MAX;
    int left, right;
    for (int k = i; k <= j - 1; k++) {
        if (dp[i][k] != -1)
            left = dp[i][k];
        else 
            left = minPartitions (str, i, k);
            dp[i][k] = left;

        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
            right = minPartitions (str, k + 1, j);
            dp[k + 1][j] = right;
        
        int tempans = 1 + left + right;
        ans = min(tempans, ans);

    }
    return dp[i][j] = ans;
}

int main() {
    memset (dp, -1, sizeof (dp));
    string str = "nitik";
    int i = 0;
    int j = str.length() - 1;
    cout << minPartitions (str, i, j) << endl;
    return 0;
}