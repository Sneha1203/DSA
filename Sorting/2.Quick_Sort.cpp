#include <iostream>
#include <algorithm>
using namespace std;

int Partition (int arr[], int l, int h) {

    int pivot = arr[l];
    int i = l;
    int j = h;

    while (i < j) {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot) 
            j--;

        if (i < j)
            swap (arr[i], arr[j]);
    }

    swap (arr[j], arr[l]);
    return j;
}

void quickSort (int arr[], int l, int h) {
    if (l < h) {
        int pivot = Partition (arr, l, h);
        quickSort (arr, l, pivot - 1);
        quickSort (arr, pivot + 1, h);
    }
}

int main() {
    int arr[] = {3, 6, 1, 5, 7, 9, 8};
    quickSort (arr, 0, 6);
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";

    }
    return 0;
}