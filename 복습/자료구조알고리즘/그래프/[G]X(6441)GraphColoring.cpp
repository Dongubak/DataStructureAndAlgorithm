#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge {
public:
   int dst;
   int weight;

   Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   vector<vector<Edge>> g;

   Graph(int size) {
      g.resize(size);
   }

   void addEdge(int src, int dst, int weight) {
      g[src].emplace_back(Edge(dst, weight));
   }
};

bool DFS_RECU(Graph& g, int v, vector<int>& color, int c) {
///현재 정점이 이분그래프인지 판별하는 동시에 깊이 우선탐색으로 책을 칠함
   color[v] = c;  // 현재 정점의 색을 설정합니다.

   for(auto& e : g.g[v]) {
      if(color[e.dst] == c) {
         // 인접한 정점이 현재 정점과 같은 색이면 이분 그래프가 아닙니다.
         return false;
      }
      if(color[e.dst] == 0 && !DFS_RECU(g, e.dst, color, -c)) {
         // 인접한 정점이 아직 색이 할당되지 않았고, 재귀적으로 탐색했을 때 이분 그래프가 아니면 false를 반환합니다.
         return false;
      }
   }
   return true;  // 이분 그래프입니다.
}

void BipartiteGraph(Graph& g, int st) {
   vector<int> color(g.g.size(), 0);  // 모든 정점을 아직 색칠하지 않은 상태로 초기화합니다.
   DFS_RECU(g, st - 1, color, 1);  // 시작 정점을 1로 색칠하며 탐색을 시작합니다.

   int count = 0;

   queue<int> q;
   for(int i = 0; i < g.g.size(); i++) {
      if(color[i] == 1) {
         count += 1;
         q.push(i + 1);
      }
   }
   cout << count << '\n';

   while(!q.empty()) {
      cout << q.front() << " ";
      q.pop();
   }
}

int main(void) {
   int n, vn, en;
   cin >> n;

   for(int i = 0; i < n; i++) {
      cin >> vn >> en;
      Graph g(vn);
      int s, d;
      for(int j = 0 ; j < en; j++) {
         cin >> s >> d;
         g.addEdge(s - 1, d - 1, 1);
         g.addEdge(d - 1, s - 1, 1);
      }

      BipartiteGraph(g, 1);

      cout << '\n';
   }

   

   return 0;
}
