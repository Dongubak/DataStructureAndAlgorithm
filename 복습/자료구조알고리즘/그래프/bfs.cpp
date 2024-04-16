#include <iostream>
#include <vector>
#include <queue>
#include <set>

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

void bfs(const Graph& g) {
   int st = 0;
   vector<int> vis(4, 0);
   vector<int> nvis(4);
   for(int i = 0; i < 4; i++) {
      nvis[i] = i;
   }

   vis[st] = 1;
   queue<int> q; q.push(st);

   while(!q.empty()) {
      int qf = q.front();
      cout << qf << " ";
      q.pop();

      for(auto ptr = g.g[qf].begin(); ptr != g.g[qf].end(); ptr++) {
         if(!vis[ptr->dst]) {
            vis[ptr->dst] = 1;
            q.push(ptr->dst);
         }
      }
   }
}

int main(void) {

   Graph g(4);

   g.addEdge(0, 1, 3);
   g.addEdge(0, 2, 5);
   g.addEdge(1, 2, 10);
   g.addEdge(2, 3, 10);

   bfs(g);

   return 0;
}