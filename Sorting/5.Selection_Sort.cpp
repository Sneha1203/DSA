#include <iostream>
using namespace std;

void selectionSort (int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap (arr[min_idx], arr[i]);
    }
}

// void selectionSort(int array[], int size) {
//   for (int step = 0; step < size - 1; step++) {
//     int min_idx = step;
//     for (int i = step + 1; i < size; i++) {
//       if (array[i] < array[min_idx])
//         min_idx = i;
//     }
//     swap(array[min_idx], array[step]);
//     for (int x = 0; x < size; x++) {
//             cout << array[x] << " ";
//         }
//         cout << endl;
//   }
// }

int main() {
    int arr[] = {3, 6, 1, 5, 7, 9, 8};
    selectionSort (arr, 7);
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";

    }
    return 0;
}