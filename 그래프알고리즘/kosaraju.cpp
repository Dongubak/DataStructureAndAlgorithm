#include <cstdio>
#include <vector>
#include <stack>
#include <list>

class Edge {
public:
    int dst;
    int weight;

    Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
    std::vector<std::list<Edge>> G;
    int size;

    Graph(int s) : size(s + 1) {
        G.resize(size);
    }

    void addEdge(int s, int d, int w) {
        G[s].push_front(Edge(d, w));
    }

    void DFS_Recursive(int v, std::vector<int>& visited, std::stack<int>& sta) {
        visited[v] = 1;

        for (auto& a : G[v]) {
            if (visited[a.dst] == 0) {
                DFS_Recursive(a.dst, visited, sta);
            }
        }

        sta.push(v);
    }

    std::stack<int> DFS_Basic() {
        std::stack<int> sta;
        std::vector<int> visited(size);
        for (int i = 1; i < size; i++) {
            if (visited[i] == 0) {
                DFS_Recursive(i, visited, sta);
            }
        }

        return sta;
    }

    Graph transp() {
        Graph ret(size);
        for (int i = 1; i < size; i++) {
            for (auto& adj : G[i]) {
                ret.addEdge(adj.dst, i, adj.weight);
            }
        }

        return ret;
    }
};

void DFS(Graph& g, int v, std::vector<bool>& visited) {
    visited[v] = true;
    printf("%d ", v);

    for (auto& adj : g.G[v]) {
        if (!visited[adj.dst]) {
            DFS(g, adj.dst, visited);
        }
    }
}

void kosaraju(Graph g) {
    std::stack<int> sta = g.DFS_Basic();
    std::vector<bool> visited(g.size, false);
    while (!sta.empty()) {
        int v = sta.top();
        sta.pop();

        if (!visited[v]) {
            printf("강한 연결 요소: ");
            DFS(g, v, visited);
            printf("\n");
        }
    }
}

int main(void) {
    using namespace std;
    int vn, en;

    scanf("%d %d", &vn, &en);

    Graph g(vn);

    int st, dst, weight;
    for (int i = 0; i < en; i++) {
        scanf("%d %d %d", &st, &dst, &weight);

        g.addEdge(st, dst, weight);
    }

    kosaraju(g);

    return 0;
}
