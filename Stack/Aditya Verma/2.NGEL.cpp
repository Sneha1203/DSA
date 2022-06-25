#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> NGEL (int arr[], int size) {
    vector <int> result;
    stack <int> s;

    for (int i = 0; i < size; i++) {
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
    return result;
}

int main() {
    int arr[] = {1, 3, 2, 4};
    int size = 4;
    vector <int> result = NGEL (arr, size);
    cout << "NGEL: ";
    for (auto i: result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}