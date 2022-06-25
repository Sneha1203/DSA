#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void DFS (vector<int> *v, int vertices, int first, int visited[]) {
    visited[first] = 1;
    cout << first << " ";

    for (auto x : v[first]) {
        if (visited[x] == 0)
            DFS (v, vertices, x, visited);
    }
}

int main() {
    int vertices, edges;
    cout << "Enter vertices and edges: ";
    cin >> vertices >> edges;

    vector <int> v[vertices + 1];

    for (int i = 1; i <= edges; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    
    int *visited = new int [vertices];
    for (int i = 0; i <= vertices; i++) {
        visited[i] = 0;
    }

    int first;
    cout << "Enter the vertex to start DFS: ";
    cin >> first;

    DFS (v, vertices, first, visited);
    return 0;
}