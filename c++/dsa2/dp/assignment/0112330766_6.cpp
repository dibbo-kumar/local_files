// 0112330766
// Dibba Kumar Biswash


#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, source, des;
    cin >> n >> m >> source >> des;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> isVisited(n, false);
    queue<int> q;
    q.push(source);
    isVisited[source] = true;
    bool found = false;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == des) {
            found = true;
            break;
        }

        for (int neighbour : graph[node]) {
            if (!isVisited[neighbour]) {
                isVisited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    cout << (found ? "true" : "false") << endl;

    return 0;
}
