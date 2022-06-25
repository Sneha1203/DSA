#include <iostream>
#include <vector>
using namespace std;

vector <int> isSubset (int arr[], int sum, int size) {
    bool dp[size + 1][sum + 1];
    dp[0][0] = true;

    for (int i = 1; i < sum + 1; i++) {
        dp[0][i] = false;
    }

    for (int i = 1; i < size + 1; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    vector <int> checkForSubset;
    for (int i = 0; i < sum + 1; i++) {
        if (dp[size][i] == true)
            checkForSubset.push_back (i);
    }
    return checkForSubset;
}


int minDiffValue (int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    vector <int> possibleValues = isSubset (arr, sum, size);
    int totalPossibleValue = possibleValues.size();
    vector <int> result;

    for (int i = 0; i < totalPossibleValue / 2; i++) {
          result.push_back (sum - possibleValues[i] * 2);
    }

    int min = INT_MAX;
    for (int i = 0; i < totalPossibleValue/2; i++) {
        if (result[i] < min) {
            min = result[i];
        }
    }
    return min;
}

int main() {
    int arr[] = {1, 2, 7};
    int size = sizeof(arr) / sizeof(int);
    cout << endl << minDiffValue (arr, size) << endl;
    return 0;
}