#include <iostream>
#include <queue>
using namespace std;

class Graph
{
private:
    int V;
    int adj[100][100];
    int color[100]; // -1: uncolored, 0 and 1: two colors

public:
    Graph(int v)
    {
        V = v;
        for (int i = 0; i < V; i++)
        {
            color[i] = -1;
            for (int j = 0; j < V; j++)
            {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v)
    {
        // Assuming 0-based indexing
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    bool isBipartite()
    {
        queue<int> q;

        for (int start = 0; start < V; start++)
        {
            if (color[start] == -1)
            { // not yet colored
                q.push(start);
                color[start] = 0;

                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();

                    for (int v = 0; v < V; v++)
                    {
                        if (adj[u][v])
                        {
                            if (color[v] == -1)
                            {
                                color[v] = 1 - color[u];
                                q.push(v);
                            }
                            else if (color[v] == color[u])
                            {
                                return false; // same color found, not bipartite
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    Graph g(4);
    // Input uses 1-based indexing, so convert to 0-based
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    if (g.isBipartite())
        cout << "Graph is Bipartite: Yes\n";
    else
        cout << "Graph is Bipartite: No\n";

    return 0;
}
