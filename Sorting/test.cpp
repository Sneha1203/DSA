#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int b[r + 1];
    while(i <= mid && j <= r) {
        if(a[i] < a[j]) {
            b[k] = a[i];
            k++;
            i++;
        } else {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    while(j<=r) {
        b[k] = a[j];
        k++;
        j++;
    }
    while(i <= mid) {
        b[k] = a[i];
        k++;
        i++;
    }

 for(int idx=l;idx<=r;idx++){
     a[idx] = b[idx];
 }
}

void mergeSort(int a[], int l, int r)
{
    while(l < r) {
        int mid = (l + r) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, mid, r);
    }
}

int main()
{
    int a[] = { 9, 4, 7, 6, 3, 1, 5 };
    mergeSort(a, 0, 6);
    for(int i = 0; i < 7; i++) {
        cout << a[i] << " ";
    }
}