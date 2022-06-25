//index of NGEL

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

vector <int> stockSpan (int arr[], int size) {
    vector <int> v;
    stack <pair <int, int>> s; // {element, index}

    for (int i = 0; i < size; i++) {
        if (s.empty()) {
            v.push_back (-1);
        }
        else if (!s.empty() & s.top().first > arr[i]) {
            v.push_back (s.top().second);
        }
        else if (!s.empty() && s.top().first <= arr[i]) {
            while (!s.empty() && s.top().first <= arr[i]) {
                s.pop();
            }
            if (!s.empty() && s.top().first > arr[i]) {
                v.push_back (s.top().second);
            } else {
                v.push_back (-1);
            }
        }
        s.push ({arr[i], i});
    } 
    for (int i = 0; i < size; i++) {
        v[i] = i - v[i];
    }
    return v;
}

int main() {
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int size = 7;
    vector <int> output = stockSpan (arr, size);
    cout << endl;
    for (auto it: output) {
        cout << it << " ";
    }
    return 0;
}