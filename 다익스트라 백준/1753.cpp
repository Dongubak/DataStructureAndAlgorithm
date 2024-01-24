#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>

class Edge {
public:
    int dst;
    int weight;

    Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
    std::vector<std::list<Edge>> vertices;

    Graph(int size) {
        vertices.resize(size + 1);
    }

    void addEdge(int src, int dst, int weight) {
        vertices[src].push_back(Edge(dst, weight));
    }
};

void dijkstra(int vn, int st, const Graph& G) {
    std::vector<int> sht(vn + 1, std::numeric_limits<int>::max());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    sht[st] = 0;
    pq.push(std::make_pair(0, st));

    while (!pq.empty()) {
        int mv = pq.top().second;
        pq.pop();

        for (const auto& edge : G.vertices[mv]) {
            if (sht[mv] != std::numeric_limits<int>::max() && sht[mv] + edge.weight < sht[edge.dst]) {
                sht[edge.dst] = sht[mv] + edge.weight;
                pq.push(std::make_pair(sht[edge.dst], edge.dst));
            }
        }
    }

    for (int i = 1; i <= vn; ++i) {
        if (sht[i] != std::numeric_limits<int>::max()) {
            std::cout << sht[i] << "\n";
        } else {
            std::cout << "INF\n";
        }
    }
}

int main() {
    int vn, en, st;
    std::cin >> vn >> en >> st;

    Graph G(vn);

    for (int i = 0; i < en; ++i) {
        int s, e, w;
        std::cin >> s >> e >> w;
        G.addEdge(s, e, w);
    }

    dijkstra(vn, st, G);

    return 0;
}