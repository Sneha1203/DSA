#include <bits/stdc++.h>
using namespace std;

void closestK (int arr[], int k, int x, int size) {
    priority_queue <pair <int, int>> maxHeap;
    for (int i = 0; i < size; i++) {
        int key = abs (arr[i] - x);
        maxHeap.push (make_pair (key, arr[i]));
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    
    while (!maxHeap.empty()) {
        cout << maxHeap.top().second << " ";
        maxHeap.pop();
    }
}

int main() {
    int arr[] = {5, 6, 7, 8, 9};
    int k = 3;
    int x = 7;
    closestK (arr, k, x, 5);
    return 0;
}