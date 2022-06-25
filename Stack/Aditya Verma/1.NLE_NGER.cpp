#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> NLE (int arr[], int size) {
    stack <int> s;
    vector <int> result;
    for (int i = size - 1; i >= 0; i--) {
        if (s.empty()) {
            result.push_back (-1);
        }
        else if (!s.empty() && s.top() > arr[i]) {
            result.push_back (s.top());
        }
        else if (!s.empty() && s.top() <= arr[i]) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
            if (!s.empty() && s.top() > arr[i]) {
                result.push_back (s.top());
            } else {
                result.push_back (-1);
            }
        }
        s.push (arr[i]);
    }
    reverse (result.begin(), result.end());
    return result;
}

int main() {
    int arr[] = {1, 3, 2, 4};
    int size = 4;
    vector <int> result = NLE (arr, size);
    cout << "NLE: ";
    for (auto i: result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}