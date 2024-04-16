#include <iostream>
#include <vector>
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

void DFS_RECU(Graph& g, int v, vector<int>& vis) {
   // g: graph
   // v : current vertex
   // vis : visited vertex
   cout << v + 1 << '\n';
   vis[v] = 1;

   for(auto ptr = g.g[v].begin(); ptr != g.g[v].end(); ptr++) {
      if(!vis[ptr->dst]) {
         DFS_RECU(g, ptr->dst, vis);
      }
   }
}

void DFS(Graph& g, int st) {
   // g : graph
   // st: start vertex

   vector<int> vis(g.g.size(), 0);
   DFS_RECU(g, st - 1, vis);
}

int main(void) {
   int vn, en;
   cin >> vn >> en;

   Graph g(vn);
   int s, d;
   for(int i = 0 ; i < en; i++) {
      cin >> s >> d;
      g.addEdge(s - 1, d - 1, 1);
      g.addEdge(d - 1, s - 1, 1);
   }

   DFS(g, 1);

   return 0;
}