#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pi;

void frequencySort (int arr[], int size) {
    map <int, int> mp; // {value, freq}
    for (int i = 0; i < size; i++) {
        mp[arr[i]]++;
    }
    priority_queue <pi> maxHeap;

    for (auto it = mp.begin(); it != mp.end(); it++){
        maxHeap.push ({it -> second, it -> first}); // {freq, value}
    }
    while (!maxHeap.empty()) {
        pair <int, int> p = maxHeap.top();
        while (p.first--) {
            cout << p.second << " ";
        }
        maxHeap.pop();
    }
}

int main() {
    int arr[] = {1,1,1,3,2,2,4};
    int size = 7;
    frequencySort (arr, size);
    return 0;
}