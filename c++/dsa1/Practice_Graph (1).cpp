/* 01. Represent a Graph Using Adjacency Matrix and Adjacency List.

#include<iostream>
using namespace std;

class Graph {
 private:
    int V;
    bool directed;
    int adjMatrix[100][100];
    int adjList[100][100];
    int listSize[100];

 public:
    Graph(int vertices, bool isDirected) {

        V = vertices;
        directed = isDirected;

        for(int i=0; i<V; i++) {

            listSize[i] = 0;

            for(int j=0; j<V; j++) {

                adjMatrix[i][j] = 0;
                adjList[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {

     adjMatrix[u - 1][v - 1] = 1;

     adjList[u - 1][listSize[u - 1]++] = v;

    if (!directed) {
        adjMatrix[v - 1][u - 1] = 1;
        adjList[v - 1][listSize[v - 1]++] = u;
    }
}

    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;

        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {

                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printAdjList() {
        cout << "Adjacency List:" << endl;

        for (int i=0; i<V; i++) {

            cout << i + 1 << ": ";

            for (int j=0; j < listSize[i]; j++) {

                cout << adjList[i][j];

                 if (j < listSize[i] - 1) cout << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4, false); // Undirected graph

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.printAdjMatrix();
    g.printAdjList();

    return 0;
}
*/








/* 02. Implement Depth-First Search(DFS)

#include<iostream>
#include<stack>
using namespace std;

class Graph {
private:
    int V;
    bool directed;
    int adj[100][100];
    bool visited[100];

public:
    Graph(int v, bool dir) {
        V = v;
        directed = dir;

        for (int i = 0; i < V; i++) {
            visited[i] = false;
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u - 1][v - 1] = 1;

        if (!directed) {
         adj[v - 1][u - 1] = 1;
        }
    }

    void initVisited() {
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
    }

    void DFS(int start) {
        //start--;
        stack<int> st;
        st.push(start - 1);
        visited[start - 1] = true;

        cout << "DFS Traversal: ";

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            cout << u + 1 << " ";

            for (int v = V - 1; v >= 0; v--) {
                if (adj[u][v] == 1 && !visited[v]) {
                    st.push(v);
                    visited[v] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5, false);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    g.initVisited();
    g.DFS(1);

    return 0;
}
*/






/* 03. Check if a Graph is Bipartite (BFS)

#include<iostream>
#include<queue>
using namespace std;

class Graph {
private:
    bool directed;
    int V;
    int adj[100][100];

public:
    Graph(int v, bool dir) {
        V = v;
        directed = dir;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        if (!directed) {
            adj[v][u] = 1;
        }
    }

    bool isBipartite() {
    int color[100];
    for(int i = 0; i < V; i++) {
        color[i] = -1;
    }

    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                for(int v = 0; v < V; v++) {
                    if(adj[u][v] == 1) {
                        if(color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if(color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
  }
};


int main() {
    int vertices = 4;
    Graph g(vertices, false);

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    if (g.isBipartite()) {
        cout << "Graph is Bipartite: Yes" << endl;
    } else {
        cout << "Graph is Bipartite: No" << endl;
    }

    return 0;
}
*/







/* 04. Find Shortest Path in an Unweighted Graph (BFS)*/

#include<iostream>
#include<queue>
using namespace std;

class Graph {
private:
    int V;
    bool directed;
    int adj[100][100];

public:
    Graph(int v, bool dir) {
        V = v;
        directed = dir;

        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        if (!directed) {
            adj[v][u] = 1;
        }
    }

    void shortestPath(int src, int dest) {
        bool visited[100];
        int parent[100];

        for (int i = 1; i <= V; i++) {
            visited[i] = false;
            parent[i] = -1;
        }

        queue<int> q;
        visited[src] = true;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = V; v >= 1; v--) {
                if (adj[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        if (!visited[dest]) {
            cout << "No path found from " << src << " to " << dest << endl;
            return;
        }

        int path[100];
        int pathLength = 0;
        int current = dest;

        while (current != -1) {
            path[pathLength++] = current;
            current = parent[current];
        }

        cout << "Shortest Path: ";
        for (int i = pathLength - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(6, false);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

    int source = 1;
    int destination = 6;

    g.shortestPath(source, destination);

    return 0;
}








/* 05. Detect a Cycle in a Directed Graph (DFS)

#include<iostream>
using namespace std;

class Graph {
private:
    bool directed;
    int V;
    int adj[100][100];
    bool visited[100];
    bool recStack[100];

public:
    Graph(int v, bool dir) {
        V = v;
        directed = dir;

        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        if (!directed) {
            adj[v][u] = 1;
        }
    }

    void init() {
        for (int i = 1; i <= V; i++) {
            visited[i] = false;
            recStack[i] = false;
        }
    }

    bool dfsCycle(int u) {
        visited[u] = true;
        recStack[u] = true;

        for (int v = 1; v <= V; v++) {
            if (adj[u][v] == 1) {
                if (!visited[v] && dfsCycle(v)) {
                    return true;
                }
                else if (recStack[v]) {
                    return true;
                }
            }
        }

        recStack[u] = false;
        return false;
    }

    bool hasCycle() {
        init();
        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                if (dfsCycle(i)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(4, true);

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);

    if (g.hasCycle()) {
        cout << "Graph contains a cycle: Yes" << endl;
    } else {
        cout << "Graph contains a cycle: No" << endl;
    }

    return 0;
}
*/











