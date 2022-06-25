#include <iostream>
using namespace std;

int faltuSawaal (int e, int f) { 
    if (f == 0 || f == 1) 
        return f;
    if (e == 1) {
        return f;
    }
    int ans = INT_MAX;
    for (int k = 1; k <= f; k++) {
        int tempans = 1 + max (faltuSawaal(e - 1, k - 1), faltuSawaal(e, f - k));
        ans = min (tempans, ans);
    }
    return ans;
}

int main() {
    cout << faltuSawaal(3, 5) << endl;
    return 0;
}