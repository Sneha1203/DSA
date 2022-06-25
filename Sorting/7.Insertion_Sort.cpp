#include <iostream>
using namespace std;

void insertionSort (int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// void insertionSort(int array[], int size) {
//   for (int step = 1; step < size; step++) {
//     int key = array[step];
//     int j = step - 1;

//     while (key < array[j] && j >= 0) {
//       array[j + 1] = array[j];
//       --j;
//     }
//     array[j + 1] = key;
//     // for (int x = 0; x < size ; x++){
//     //     cout << array[x] << " ";
//     // }
//     // cout << endl;
//   }
// }

int main() {
    int arr[] = {3, 6, 1, 5, 7, 9, 8};
    insertionSort (arr, 7);
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";

    }
    return 0;
}