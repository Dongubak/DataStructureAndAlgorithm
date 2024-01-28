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

    Graph(int s) : size(s) {
        G.resize(s);
    }

    void addEdge(int s, int d, int w) {
        G[s].push_back(Edge(d, w));
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

void DFS_Recursive(Graph& g, int v, std::vector<int>& visited, std::stack<int>& st) {
    visited[v] = 1;
    for(auto& e: g.G[v]) {
        if(visited[e.dst] == 0) {
            DFS_Recursive(g, e.dst, visited, st);
        }
    }
    st.push(v);
}

void DFS_Recursive(Graph& g, int v, std::vector<int>& visited) {
    visited[v] = 1;
    printf("%d\n", v);
    for(auto& e: g.G[v]) {
        if(visited[e.dst] == 0) {
            DFS_Recursive(g, e.dst, visited);
        }
    }
}

std::stack<int> DFS(Graph& g) {
    std::stack<int> st;
    std::vector<int> visited(g.size, 0);
    DFS_Recursive(g, 1, visited, st);

    return st;
}

void DFS(Graph& g, int v) {
    std::vector<int> visited(g.size, 0);
    DFS_Recursive(g, v, visited);
}

void kosaraju(std::stack<int> seq, Graph& tr_g) {
    std::vector<int> visited(tr_g.size, 0);
    
    while(!seq.empty()) {
        if(visited[seq.top()] == 0) {
            DFS_Recursive(tr_g, seq.top(), visited);
            printf("------\n");
        }
        seq.pop();
    }
}

int main(void) {
    using namespace std;
    int vn, en;

    scanf("%d %d", &vn, &en);

    Graph g(vn + 1);

    int st, dst, weight;
    for (int i = 0; i < en; i++) {
        scanf("%d %d %d", &st, &dst, &weight);
        g.addEdge(st, dst, weight);
    }

    Graph tr_g = g.transp();

    std::stack<int> seq = DFS(g);

    kosaraju(seq, tr_g);

    return 0;
}
