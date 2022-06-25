// only for DAG

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort (int indegree[], vector <int> *v, int vertices) {

    queue <int> q;

    for (int i = 1; i < vertices + 1; i++) {
        if (indegree[i] == 0) {
            q.push (i);
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (auto i : v[x]) {
            indegree[i]--;
            if (indegree[i] == 0) {
                q.push (i);
            }
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    int indegree[vertices + 1] = {0};
    vector <int> v[vertices + 1];

    for (int i = 1; i <= edges; i++) {
        int v1, v2;
        cout << "Enter edge: ";
        cin >> v1 >> v2;
        v[v1].push_back (v2);
        indegree [v2]++;
    }

    topologicalSort (indegree, v, vertices);
    return 0;
}