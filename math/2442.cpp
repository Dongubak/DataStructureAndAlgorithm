#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
   int dst;
   int weight;
   Edge(int d, int w) : dst(d), weight(w) {}

   bool operator<(const Edge e1) const {
      return dst < e1.dst;
   }
};

class Graph {
public:
   int size;
   vector<list<Edge>> g;

   Graph(int s) : size(s) {
      g.resize(s);
   }

   void addEdge(int src, int dst, int wei) {
      g[src].push_back(Edge(dst, wei));
   }
};

void DFS_Recursive(int cur, Graph& g, vector<int>& visited, int dep) {
   visited[cur] = dep;

   g.g[cur].sort();

   for(auto ptr = g.g[cur].begin(); ptr != g.g[cur].end(); ptr++) {
      if(visited[ptr->dst] == -1) {
         DFS_Recursive(ptr->dst, g, visited, dep + 1);
      }
   }
}

void DFS(int st, Graph& g) {
   vector<int> visited(g.size + 1, -1);
   DFS_Recursive(st, g, visited, 0);

   for(int i = 1; i < g.size; i++) {
      cout << visited[i] << '\n';
   }
}

int main(void) {

   ///unvisited vertex's depth -> -1
   ///print all verticies' depth
   int vn, en, st, sr, ds;
   
   cin >> vn >> en >> st;

   Graph g(vn + 1);
   for(int i = 0; i < en; i++) {
      cin >> sr >> ds;
      g.addEdge(sr, ds, 1);
      g.addEdge(ds, sr, 1);
   }

   DFS(st, g);

   return 0;
}