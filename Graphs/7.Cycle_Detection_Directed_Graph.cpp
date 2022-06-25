#include <iostream>
#include <vector>
using namespace std;

bool isCycle (int src, vector <int> *v, int visited[], int stack[]) {
    visited[src] = 1;
    stack[src] = 1;
    for (auto i : v[src]) {
        if (!visited[i] && isCycle (i, v, visited, stack)) {
            return true;
        }
        if (stack[i]) {
            return true;
        }
    }
    
    stack[src] = 0;
    return false;
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector <int> v[vertices + 1];
    int visited[vertices + 1] = {0};
    int stack[vertices + 1] = {0};

    for (int i = 1; i <= edges; i++) {
        int v1, v2;
        cout << "Enter edge: ";
        cin >> v1 >> v2;
        v[v1].push_back (v2);
    }

    bool cycle = false;

    for (int i = 1; i < vertices + 1; i++) {
        if (!visited[i] && isCycle (i, v, visited, stack)) {
            cycle = true;
        }
    }

    if (cycle) {
        cout << "CYCLE IS PRESENT.\n";
    } else {
        cout << "CYCLE IS NOT PRESENT.\n";
    }
    return 0;
}