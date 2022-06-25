#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool ispalindrome (string str) {
    string checkstr = str;
    reverse (checkstr.begin(), checkstr.end());
    if (str == checkstr) {
        return true;
    } else {
        return false;
    }
}

int minPartitionsRecursive (string str, int i, int j) {
    if (i >= j) {
        return 0;
    }
    if (ispalindrome(str) == true) {
        return 0;
    }
    int minPartitions = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        int tempans = minPartitionsRecursive(str, i, k) + minPartitionsRecursive(str, k + 1, j) + 1;
        minPartitions = min (tempans, minPartitions);
    }
    return minPartitions;
}

int main() {
    string str = "ababbbabbababa";
    int i = 0;
    int j = str.length() - 1;
    cout << minPartitionsRecursive (str, i, j) << endl;
    return 0;
}