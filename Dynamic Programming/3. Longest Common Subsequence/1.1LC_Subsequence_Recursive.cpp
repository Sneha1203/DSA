#include <iostream>
#include <string>
using namespace std;

int lcsRecursive (string x, string y, int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    } else if (x[n - 1] == y[m - 1]) {
        return 1 + lcsRecursive (x, y, n - 1, m - 1);
    } else {
        return max (lcsRecursive (x, y, n - 1, m), lcsRecursive (x, y, n, m - 1));
    }
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
    cout << endl << lcsRecursive (x, y, n, m) << endl;
    return 0;
}