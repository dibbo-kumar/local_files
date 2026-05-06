#include <bits/stdc++.h>
using namespace std;

// Find parent function (for DSU)
int findParent(int node, vector<int>& parent) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent); // path compression
}

// Union function
void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            parent[a] = b;
        else if (rank[a] > rank[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // number of vertices and edges

    vector<vector<int>> edges; // each edge will be {weight, u, v}

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    // Sort by weight (edges[i][0] is weight)
    sort(edges.begin(), edges.end());

    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int totalWeight = 0;
    vector<pair<int, int>> mst; // store final edges

    for (auto &edge : edges) {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (findParent(u, parent) != findParent(v, parent)) {
            totalWeight += w;
            mst.push_back({u, v});
            unionSet(u, v, parent, rank);
        }
    }

    cout << "Minimum Spanning Tree edges:\n";
    for (auto &e : mst)
        cout << e.first << " - " << e.second << endl;

    cout << "Total Weight of MST: " << totalWeight << endl;
}
