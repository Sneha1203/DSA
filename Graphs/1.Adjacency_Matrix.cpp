#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter vertices and edges: ";
    cin >> vertices >> edges;

    vector<int> v[vertices + 1];

    for (int i = 0; i < vertices + 1; i++) {
        for (int j = 0; j < vertices + 1; j++) {
            v[i].push_back(0);
        }
    }
    
    for (int i = 1; i <= edges; i++) {
        int v1, v2;
        cout << "Enter edge (v1, v2): ";
        cin >> v1 >> v2;
        v[v1][v2] = 1;
        v[v2][v1] = 1;
    }

    for (int i = 1; i < vertices + 1; i++) {
        for (int j = 1; j < vertices + 1; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}