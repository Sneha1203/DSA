#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int t[1001][1001];

int lcsMemoized (string x, string y, int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }

    if (t[n][m] != -1) {
        return t[n][m];
    }

    if (x[n - 1] == y[m - 1]) {
        t[n][m] = 1 + lcsMemoized (x, y, n - 1, m - 1);  
    } else {
        t[n][m] = max (lcsMemoized (x, y, n - 1, m), lcsMemoized (x, y, n, m - 1));
    }
    return t[n][m];
}

int main() {
    memset (t, -1, sizeof(t));
    string x, y;
    int n, m;
    cout << "Enter string 1: ";
    cin >> x;
    cout << "Enter string 2: ";
    cin >> y;
    n = x.length();
    m = y.length();
    cout << endl << lcsMemoized (x, y, n, m) << endl;
    return 0;
}