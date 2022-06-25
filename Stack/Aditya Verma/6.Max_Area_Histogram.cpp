//index NSEL & NSER 

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

int maxAreaHistogram (int arr[], int size) {
    vector <int> NSER;
    vector <int> NSEL;
    vector <int> area;
    stack <pair <int, int>> s; // {element, index}

    for (int i = 0; i < size; i++) {
        if (s.empty()) {
            NSEL.push_back (-1);
        }
        else if (!s.empty() & s.top().first < arr[i]) {
            NSEL.push_back (s.top().second);
        }
        else if (!s.empty() && s.top().first >= arr[i]) {
            while (!s.empty() && s.top().first >= arr[i]) {
                s.pop();
            }
            if (!s.empty() && s.top().first < arr[i]) {
                NSEL.push_back (s.top().second);
            } else {
                NSEL.push_back (-1);
            }
        }
        s.push ({arr[i], i});
    }

    while (!s.empty()) {
        s.pop();
    }

    for (int i = size - 1 ; i >= 0; i--) {
        if (s.empty()) {
            NSER.push_back (size);
        }
        else if (!s.empty() & s.top().first < arr[i]) {
            NSER.push_back (s.top().second);
        }
        else if (!s.empty() && s.top().first >= arr[i]) {
            while (!s.empty() && s.top().first >= arr[i]) {
                s.pop();
            }
            if (!s.empty() && s.top().first < arr[i]) {
                NSER.push_back (s.top().second);
            } else {
                NSER.push_back (size);
            }
        }
        s.push ({arr[i], i});
    }
    reverse (NSER.begin(), NSER.end());
    
    // for (auto it : NSER) {
    //     cout << it << " ";
    // }
    // cout << endl; 

    // for (auto it : NSEL) {
    //     cout << it << " ";
    // }

    for (int i = 0; i < size; i++) {
        int x = arr[i] * (NSER[i] - NSEL[i] - 1);
        area.push_back (x);
    }

    // cout << endl;

    // for (auto it : area) {
    //     cout << it << " ";
    // }
    
    int maxArea = INT_MIN;
    for (auto it : area) {
        if (it > maxArea) {
            maxArea = it;
        }
    }
    return maxArea;
}

int main() {
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int size = 7;
    cout << "\nMAXIMUM AREA: " << maxAreaHistogram (arr, size);
    return 0;
}

