// 0112330766
// Dibba Kumar Biswash

#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(int src, vector<vector<pair<int, long long>>> &graph)
{
    int N = graph.size();
    vector<long long> dist(N, LLONG_MAX / 2);
    dist[src] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        pair<long long, int> cur = pq.top();
        pq.pop();

        long long d = cur.first;
        int u = cur.second;

        if (d > dist[u])
            continue;

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            long long w = graph[u][i].second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--)
    {
        int N, M, L;
        cout << "Enter N (cities), M (roads), and L (sequence length): ";
        cin >> N >> M >> L;

        vector<int> B(L);
        cout << "Enter sequence B: ";
        for (int i = 0; i < L; i++)
        {
            cin >> B[i];
            B[i]--;
        }

        vector<vector<pair<int, long long>>> graph(N);

        cout << "Enter roads (u v w):\n";
        for (int i = 0; i < M; i++)
        {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            u--;
            v--;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        int lastImportant = 0;
        int minK = 1;
        bool valid = true;
        int i = 1;

        while (i < L)
        {
            vector<long long> dist = dijkstra(B[lastImportant], graph);
            int j = i;
            long long pathSum = 0;

            while (j < L)
            {
                bool edgeExists = false;

                for (int k = 0; k < graph[B[j - 1]].size(); k++)
                {
                    if (graph[B[j - 1]][k].first == B[j])
                    {
                        pathSum += graph[B[j - 1]][k].second;
                        edgeExists = true;
                        break;
                    }
                }

                if (!edgeExists)
                {
                    valid = false;
                    break;
                }

                if (dist[B[j]] != pathSum)
                    break;

                j++;
            }

            if (j == i)
                valid = false;

            if (!valid)
            {
                minK = -1;
                break;
            }

            lastImportant = j - 1;
            minK++;
            i = j;
        }

        cout << "Minimum K: " << minK << endl;
    }

    return 0;
}
