#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
const int WHITE = 0, GRAY = 1, BLACK = 2;

int adj[MAX][MAX]; // adjacency matrix
int color[MAX];    // WHITE, GRAY, BLACK
int parent[MAX];

bool bfsCycleDetect(int V, int start)
{
    for (int i = 0; i < V; i++)
    {
        color[i] = WHITE;
        parent[i] = -1;
    }

    queue<int> q;
    color[start] = GRAY;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v])
            { // edge u -> v
                if (color[v] == GRAY)
                {
                    // Back edge found → cycle
                    return true;
                }
                if (color[v] == WHITE)
                {
                    color[v] = GRAY;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        color[u] = BLACK;
    }

    return false;
}
