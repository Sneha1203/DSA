#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair <int, int>> ppi;

void KclosestFromOrigin (int arr[][2], int k, int row, int column) {
    priority_queue <ppi> maxHeap;
    for (int i = 0; i < row; i++) {
        int x = arr[i][0];
        int y = arr[i][1];
        int dist = ((x * x) + (y * y));
        pair <int, int> points = make_pair (arr[i][0], arr[i][1]);
        maxHeap.push (make_pair (dist, points));

        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    while (!maxHeap.empty()) {
        cout << maxHeap.top().first << " " << maxHeap.top().second.first << " " << maxHeap.top().second.second << endl;
        maxHeap.pop();
    }
}

int main() {
    int arr[][2] = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;
    KclosestFromOrigin (arr, k, 4, 2);
    return 0;
}