#include <iostream>
#include <string>
using namespace std;

string howSum (int target, int arr[], int size) {
    if (target == 0) {
        string s = "";
        // *s = "";
        return s;
    }
    if (target < 0) 
        return {};
    
    for (int i = 0; i < size; i++) {
        int rem = target - arr[i];
        string temp = howSum (rem, arr, size);
        if (temp.size() != 0) {
            temp = temp + " " + to_string (arr[i]);
            return temp;
        } else {
            return {};
        }
    }
    return {};
    
}

int main() {
    int arr[] = {5, 3, 4, 7};
    cout << howSum(7, arr, 4)<< endl;
    return 0;
}