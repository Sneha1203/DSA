#include <iostream>
#include <queue>
using namespace std;

void largestK (int arr[], int k, int size) {
    priority_queue <int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < size; i++) {
        minHeap.push (arr[i]);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    //cout << minHeap.top() << endl; // for Kth largest 
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}

int main() {
    int arr[] = {7, 10, 3, 4, 20, 15};
    int k = 3;
    largestK (arr, k, 6);
    return 0;
}