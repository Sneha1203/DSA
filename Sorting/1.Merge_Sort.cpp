#include <iostream>
using namespace std;

void merge (int arr[], int l, int mid, int r) {

    int *merged = new int [r + 1];
    int i = l;
    int j = mid + 1;
    int k = l;

    while (i <= mid && j <= r) {

        if (arr[i] < arr[j]) {
            merged[k] = arr[i];
            k++;
            i++;
        } else {
            merged[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        merged[k] = arr[i];
        k++;
        i++;
    }

    while (j <= r) {
        merged[k] = arr[j];
        k++;
        j++;
    }

    for (int a = l; a <=r; a++) {
        arr[a] = merged [a];
    }
    free (merged);
}

void mergeSort (int arr[], int l, int r) {

    if (l < r) {
        int mid = (l+r)/2;
        mergeSort (arr, l, mid);
        mergeSort (arr, mid + 1, r);
        merge (arr, l, mid, r);
    }
}

int main() {
    int arr[] = {3, 6, 1, 5, 7, 9, 8};
    mergeSort (arr, 0, 6);
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}