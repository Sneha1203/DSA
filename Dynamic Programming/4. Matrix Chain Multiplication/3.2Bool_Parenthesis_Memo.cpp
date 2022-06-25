#include <iostream>
#include <string>
#include <cstring>
#include "unordered_map"
using namespace std;

unordered_map <string, int> mp;

int solve (string s, int i, int j, bool isTrue) {
    if (i > j)
        return 0;
    if (i == j) {
        if (isTrue == true) {
            return s[i] == 'T';
        } else {
            return s[i] == 'F';
        }
    }

    string keystr = to_string(i);
    keystr.append(" ");
    keystr.append(to_string(j));
    keystr.append(" ");
    keystr.append(to_string(isTrue));

    if (mp.find(keystr) != mp.end())
        return mp[keystr];

    int ans = 0;
        for (int k = i + 1; k <= j - 1; k+=2) {
        int leftTrue = solve (s, i, k - 1, true);
        int leftFalse = solve (s, i, k - 1, false);
        int rightTrue = solve (s, k + 1, j, true);
        int rightFalse = solve (s, k + 1, j, false);

        if (s[k] == '&') {
            if (isTrue == true) {
                ans += (leftTrue * rightTrue);
            } else {
                ans += (leftFalse * rightFalse) + (leftFalse * rightTrue) + (rightFalse * leftTrue);
            }
        } else if (s[k] == '|') {
            if (isTrue == true) {
                ans += (leftFalse * rightTrue) + (rightFalse * leftTrue) + (leftTrue * rightTrue);
            } else {
                ans += (leftFalse * rightFalse);
            }
        } else if (s[k] == '^') {
            if (isTrue == true) {
                ans += (leftFalse * rightTrue) + (rightFalse * leftTrue);
            } else {
                ans += (leftTrue * rightTrue) + (leftFalse * rightFalse);
            }
        }
    }
    
    return mp[keystr] = ans;
}

int main() {
    string str = "T^F|F";
    int i = 0;
    int j = str.length() - 1;
    bool isTrue = true;
    cout <<solve (str, i, j, isTrue) << endl;
    return 0;
}