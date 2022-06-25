#include <iostream>
#include <vector>
using namespace std;

int connectedComponents (int src, vector <int> *v, int visited[]) {
    if (visited[src])
        return 0;

    visited [src] = 1;
    int size = 1;
    for (auto i : v[src]) {
        if (!visited[i]) {
            size += connectedComponents (i, v, visited);
            visited[i] = 1;
        }
    }
    return size;
}

int numberOfWays (vector <int> components, int vertices) {
    int choices = 0;

    for (auto it : components) {
        choices += it * (vertices - it);
    }
    return choices/2;
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    vector <int> v [vertices + 1];
    int visited [vertices + 1] = {0};
    vector <int> components;
    for (int i = 1; i <= edges; i++) {
        int v1, v2;
        cout << "Enter edge: ";
        cin >> v1 >> v2;
        v[v1].push_back (v2);
        v[v2].push_back (v1);
    }

    for (int i = 1; i < vertices + 1; i++) {
        if (!visited[i]) {
            components.push_back (connectedComponents (i, v, visited));
        }
    }

    cout << "\nTotal number of ways: " << numberOfWays (components, vertices);
    return 0;  
}