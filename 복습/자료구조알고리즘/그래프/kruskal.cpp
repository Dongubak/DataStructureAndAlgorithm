#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Edge {
public:
    int src, dst, weight;
    Edge(int s, int d, int w) : src(s), dst(d), weight(w) {}

    bool operator<(const Edge& e) const {
        return weight < e.weight; // 낮은 가중치가 우선순위 큐의 앞에 오도록
    }
};

// 디스조인트 셋 클래스
class DisjointSet {
private:
    vector<int> parent;
public:
    DisjointSet(int n) : parent(n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]); // 경로 압축
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) parent[u] = v; // u의 루트를 v의 루트에 연결
    }
};

void MST(vector<Edge>& edges, int V) {
   sort(edges.begin(), edges.end()); // 간선 가중치에 따라 오름차순 정렬
   DisjointSet sets(V);
   int sum = 0;
   for (const auto& e : edges) {
      if (sets.find(e.src) != sets.find(e.dst)) { // 사이클이 형성되지 않으면
         sum += e.weight;
         sets.merge(e.src, e.dst); // 간선을 MST에 추가
      }
   }
   cout << sum;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges;

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u - 1, v - 1, w); // 0-based 인덱스로 변환
    }

    MST(edges, V);

    return 0;
}
