// 0112330766
// Dibba Kumar Biswash

#include <bits/stdc++.h>
using namespace std;

int n;
int mat[100][100];
vector<int> dijk(int s)
{
    vector<int> dis(n, INT_MAX);
    dis[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        int t = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (t > dis[u])
            continue;
        for (int v = 0; v < n; v++)
        {
            if (mat[u][v] > 0 && dis[u] + mat[u][v] < dis[v])
            {
                dis[v] = dis[u] + mat[u][v];
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

int main()
{
    cout << "enter value of n : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int s, g, d;
        cin >> s >> g >> d;

        vector<int> fromS = dijk(s);
        vector<int> fromG = dijk(g);

        int t1 = fromS[g] + fromG[d];
        int t2 = fromS[d];
        int save = t1 - t2;

        cout << t1 << " " << save << endl;
    }

    return 0;
}
