#include <bits/stdc++.h>
using namespace std;

int KthSmallest (int arr[], int k, int size) {
    priority_queue <int> maxHeap;
    for (int i = 0; i < size; i++) {
        maxHeap.push (arr[i]);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main() {
    int arr[] = {1,3,12,5,15,11};
    int k1 = 3;
    int k2 = 6;
    int k1Smallest = KthSmallest (arr, k1, 6);
    int k2Smallest = KthSmallest (arr, k2, 6);
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        if (arr[i] > k1Smallest && arr[i] < k2Smallest){
            sum += arr[i];
        }
    }
    cout << endl << sum << endl;
    return 0;
}