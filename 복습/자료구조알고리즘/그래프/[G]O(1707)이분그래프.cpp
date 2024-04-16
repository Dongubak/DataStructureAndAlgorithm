#include <iostream>
#include <vector>
#include <algorithm>

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

bool DFS_RECU(Graph& g, int v, vector<int>& color, int c, vector<int>& vis) {
   ///현재 정점이 이분그래프인지 판별하는 동시에 깊이 우선탐색으로 책을 칠함
   color[v] = c;  // 현재 정점의 색을 설정합니다.
   vis[v] = 1;

   for(auto& e : g.g[v]) {
      if(color[e.dst] == c) {
         // 인접한 정점이 현재 정점과 같은 색이면 이분 그래프가 아닙니다.
         return false;
      }
      if(color[e.dst] == 0 && !DFS_RECU(g, e.dst, color, -c, vis)) {
         // 인접한 정점이 아직 색이 할당되지 않았고, 재귀적으로 탐색했을 때 이분 그래프가 아니면 false를 반환합니다.
         return false;
      }
   }
   return true;
}

bool isBipartiteGraph(Graph& g, int st) {
   vector<int> color(g.g.size(), 0); // 모든 정점을 아직 색칠하지 않은 상태로 초기화합니다.
   vector<int> vis(g.g.size(), 0);

   vector<int>::iterator iter;
   while((iter = find(vis.begin(), vis.end(), 0)) != vis.end()) {
      if(!DFS_RECU(g, iter - vis.begin(), color, 1, vis)) {
         return false;
      }
   }
   return true;
}

int main(void) {
   int n, vn, en;

   cin >> n;

   for(int i = 0; i < n; i++) {
      cin >> vn >> en;  
      Graph g(vn);
      int s, d;
      for(int i = 0 ; i < en; i++) {
         cin >> s >> d;
         g.addEdge(s - 1, d - 1, 1);
         g.addEdge(d - 1, s - 1, 1);
      }

      if(isBipartiteGraph(g, 1)) {  // 첫 번째 정점을 기준으로 이분 그래프 판별을 시작합니다.
         cout << "YES" << '\n';
      } else {
         cout << "NO" << '\n';
      }
   }
   

   return 0;
}
