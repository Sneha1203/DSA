#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minMultiplicationRecursive (int arr[], int i, int j) {
    if (i >= j) {
        return 0;
    }
    int minMultiplications = INT16_MAX;
    for (int k = i; k <= j - 1; k++) {
        int tempans = minMultiplicationRecursive(arr, i, k) + minMultiplicationRecursive (arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (tempans < minMultiplications) {
            minMultiplications = tempans;
        }
    }
    return minMultiplications;
}

int main() {
    int arr[] = {40, 20, 30, 10, 30};
    int i = 1;
    int j = (sizeof(arr) / sizeof(int)) - 1;
    cout << minMultiplicationRecursive (arr, i, j) << endl;
    return 0;
}