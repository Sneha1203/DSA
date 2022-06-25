#include <iostream>
#include <queue>
using namespace std;

void sortNearlySorted (int arr[], int k, int size) {
    priority_queue <int, vector <int>, greater <int>> minHeap;
    for (int i = 0; i < size; i++) {
        minHeap.push (arr[i]);
        if (minHeap.size() > k) {
            cout << minHeap.top() << " ";
            minHeap.pop();
        }
    }
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
   }  
}

int main() {
    int arr[] = {6, 5, 3, 2, 10, 8, 9};
    int k = 3;
    sortNearlySorted (arr, k, 7);
    return 0;
}