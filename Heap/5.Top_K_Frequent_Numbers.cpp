#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pi;

void topKFrequency (int arr[], int k, int size) {
    unordered_map <int, int>mp; // {value, frequency}
    for (int i = 0; i < size; i++) {
        mp[arr[i]]++;
    }

    // for (auto it = mp.begin(); it != mp.end(); it++){
    //     cout << it -> first << " " << it -> second << endl;
    // }

    priority_queue <pi, vector <pi>, greater <pi>> minHeap;
    // map <int, int> :: iterator it;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        minHeap.push ({it->second, it->first}); // {key, value}

        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    while (!minHeap.empty()) {
        cout << minHeap.top().first << " " << minHeap.top().second << endl;
        minHeap.pop();
    }
}

int main() {
    int arr[] = {1,1,1,3,2,2,4};
    int k = 2;
    int size = 7;
    topKFrequency (arr, k, size);
    return 0;
}