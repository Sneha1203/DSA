#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;

void BFS (vector<int> *v, int vertices, int first) {
    int visited[vertices] = {0};
    queue <int> q;

    q.push (first);
    visited [first] = 1;

    while (!q.empty()) {
        int vertex = q.front();
        // int n = v[vertex].size();
        q.pop();
        cout << vertex << " ";

        for (auto x : v[vertex]){
            if (visited[x] == 0) {
                q.push(x);
                visited[x] = 1;
            }
        }
        // for (int i = 0; i < n; i++) {
        //     if (visited[v[vertex][i]] == 0) {
        //         q.push (v[vertex][i]);
        //         visited[v[vertex][i]] = 1;
        //     }
        // }
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

    int first;
    cout << "Enter the vertex to start BFS: ";
    cin >> first;
    BFS (v, vertices, first);
    return 0;

}