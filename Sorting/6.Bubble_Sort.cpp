#include <iostream>
using namespace std;

// All the comparisons are made even if the array is already sorted.This increases the execution time
// we can introduce an extra variable swapped. The value of swapped is set true if there occurs swapping of elements. 
// Otherwise, it is set false.
// After an iteration, if there is no swapping, the value of swapped will be false. 
// This means elements are already sorted and there is no need to perform further iterations.
// This will reduce the execution time and helps to optimize the bubble sort.

void bubbleSort (int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap (arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        // for (int x = 0; x < n; x ++) {
        //     cout << arr[x] << " ";
        // }
        // cout << endl;
        if (swapped == 0)
            break;
    }
}

int main() {
    int arr[] = {3, 6, 1, 5, 7, 9, 8};
    bubbleSort (arr, 7);
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}