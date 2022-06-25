for (auto x : v[vertex]){
            if (visited[x] == 0) {
                q.push(x);
                visited[x] = 1;
            }
        }