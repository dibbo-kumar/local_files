// 0112330766
// Dibba Kumar Biswash

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int findMinNode(const vector<int> &weight, const vector<bool> &visited, int n)
{
    int minVal = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && weight[i] < minVal)
        {
            minVal = weight[i];
            minIndex = i;
        }
    }
    return minIndex;
}

vector<vector<int>> primMST(vector<vector<int>> &graph, int n)
{
    vector<int> parent(n, -1);
    vector<int> weight(n, INT_MAX);
    vector<bool> visited(n, false);

    weight[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int u = findMinNode(weight, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < weight[v])
            {
                weight[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    vector<vector<int>> mstEdges;
    for (int i = 1; i < n; i++)
    {
        mstEdges.push_back({parent[i] + 1, i + 1, graph[i][parent[i]]});
    }
    return mstEdges;
}

vector<vector<int>> readTestCase()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    return primMST(graph, n);
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        vector<vector<int>> mst = readTestCase();
        for (int j = 0; j < mst.size(); j++)
        {
            cout << mst[j][0] << " " << mst[j][1] << " " << mst[j][2] << "\n";
        }
    }

    return 0;
}
