#include <iostream>
#include <vector>
using namespace std;


int main() {
    int vertices, edges;
    cout << "Enter vertices and edges: ";
    cin >> vertices >> edges;

    vector <int> v[vertices + 1];

    for (int i = 1; i <= edges; i++) {
        int v1, v2;
        cout << "Enter edge (v1, v2): ";
        cin >> v1 >> v2;
        v[v1].push_back(v2); 
        v[v2].push_back(v1); 
    }

    // for (int i = 1; i < vertices + 1; i++) {
    //     int x = v[i].size();
    //     cout << i << "  ";
    //     for (int j = 1; j < x; j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
for (int i = 1; i < vertices + 1; i++) {
    cout << i << "  ->  ";
        for (auto x : v[i]) {
            cout << x << " ";
    }
    cout << endl;
}
    
} 