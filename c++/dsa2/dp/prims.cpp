#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<pair<int, int>>> adj(n);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;
        inMST[u] = true;

        for (auto edge : adj[u])
        {
            int v = edge.first, w = edge.second;
            if (!inMST[v] && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    int total = 0;
    cout << "\nEdges in MST:\n";
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i << "\n";
        total += key[i];
    }
    cout << "Total Weight: " << total << endl;

    return 0;
}
