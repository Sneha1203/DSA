#include <iostream>
#include <vector>
using namespace std;

bool result;

void isBipartite (vector <int> *v, int vertices, int visited[], int color[], int src, int currentColor) {
    if (color[src] != -1 && color[src] != currentColor) {
        result = false;
        return;
    }
    color[src] = currentColor;
    if (visited[src]) {
        return;
    }
    visited[src] = 1;
    for (auto it : v[src]) {
        isBipartite (v, vertices, visited, color, it, currentColor xor 1);
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    vector <int> v[vertices + 1];
    int visited[vertices + 1] = {0};
    int color[vertices + 1] = {-1};
    result = true;

    for (int i = 1; i <= edges; i++) {
        int v1, v2;
        cout << "Enter edge: ";
        cin >> v1 >> v2;
        v[v1].push_back (v2);
        v[v2].push_back (v1);
    }

    for (int i = 1; i < vertices + 1; i++) {
        if (!visited[i]) {
            isBipartite (v, vertices, visited, color, i, 0);
        }
    }

    if (result) {
        cout << "\nGRAPH IS BIPARTITE.\n";
    } else {
        cout << "\nGRAPH IS NOT BIPARTITE.\n";
    }
    return 0;
}