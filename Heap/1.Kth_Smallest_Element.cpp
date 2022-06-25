#include <iostream>
#include <queue>
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
    int arr[] = {7, 10, 3, 4, 20, 15};
    int k = 3;
    cout << KthSmallest (arr, k, 6);
}