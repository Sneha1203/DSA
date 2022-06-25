#include <bits/stdc++.h>
using namespace std;

int connectRopes (int arr[], int size) {
    priority_queue <int , vector <int>, greater <int>> minHeap;
    int minCost = 0;
    for (int i = 0; i < size; i++) {
        minHeap.push (arr[i]);
    }
    while (minHeap.size() >= 2) {
        int s1 = minHeap.top();
        minHeap.pop();
        int s2 = minHeap.top();
        minHeap.pop();
        int minLength = s1 + s2;
        minHeap.push (minLength);
        minCost += minLength;
    }
    return minCost;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    cout << connectRopes (arr, size) << endl;
    return 0;
}