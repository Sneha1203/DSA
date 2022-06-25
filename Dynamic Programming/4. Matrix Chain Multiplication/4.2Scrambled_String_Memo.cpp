#include <iostream>
#include <string>
#include <cstring>
#include "unordered_map"
using namespace std;

unordered_map <string, bool> mp;

bool solve (string x, string y) {
    if (x.compare(y) == 0)
        return true;
    if (x.length() <= 1)
        return false;
    
    string keystr = x;
    keystr.append(" ");
    keystr.append(y);

    if (mp.find(keystr) != mp.end()) {
        return mp[keystr];
    }

    int n = x.length();
    bool flag = false;
    for (int i = 1; i <= n - 1; i++) {
        bool cond1 = (solve (x.substr(0, i), y.substr(n - i, i)) && solve (x.substr(i, n - i), y.substr(0, n - i)));
        bool cond2 = (solve (x.substr(0, i), y.substr(0, i)) && solve(x.substr(i, n - i), y.substr(i, n - i)));

        if (cond1 || cond2) {
            flag = true;
            break;
        }
    }
    return mp[keystr] = flag;

}

bool check (string x, string y) {
    if (x.length() != y.length())
        return false;
    if (x == " " && y == " ")
        return true;
    return solve (x, y);
}

int main() {
    string x = "great";
    string y = "grate";
    cout << check (x, y) << endl;
    return 0;
}
