#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <tuple>
#include <numeric>

class Edge {
public:
   int dst;
   int weight;

   Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   int size;
   std::vector<std::list<Edge>> G;
   
   Graph(int s) : size(s) {
      G.resize(s);
   }

   void addEdge(int s, int d, int w) {
      G[s].push_back(Edge(d, w));
   }
};

void BFS(Graph& g, int st) {
   std::queue<int> q;
   std::vector<int> visited(g.size);

   visited[st] = 1;
   q.push(st);
   printf("%d\n", st);  
   while(!q.empty()) {
      int pv = q.front();
      q.pop();

      for(auto e: g.G[pv]) {
         if(visited[e.dst] == 0) {
            printf("%d\n", e.dst);
            visited[e.dst] = 1;
            q.push(e.dst);
         }
      }
   }
}

void DFS_Recusrive(Graph& g, int cv, std::vector<int>& visited) {
   visited[cv] = 1;
   printf("%d\n", cv);

   for(auto& e: g.G[cv]) {
      if(visited[e.dst] == 0) {
         DFS_Recusrive(g, e.dst, visited);
      }
   }
}

void DFS(Graph& g, int st) {
   std::vector<int> visited(g.size, 0);
   DFS_Recusrive(g, st, visited);
}

void Prim(Graph& g, int st) {
   std::vector<int> distance(g.size, std::numeric_limits<int>::max());
   
   std::priority_queue<std::tuple<int, int,int>> pq;
   std::vector<int> visited(g.size, 0);
   
   for(auto& e : g.G[st]) { ///weight, dst, src
      pq.push(std::make_tuple(e.weight, e.dst, st));
   }
}

int main(void) {

   Graph g(9);
   g.addEdge(1, 2, 2);
   g.addEdge(1, 5, 3);
   g.addEdge(2, 1, 2);
   g.addEdge(2, 5, 5);
   g.addEdge(2, 4, 1);
   g.addEdge(3, 4, 2);
   g.addEdge(3, 7, 3);
   g.addEdge(4, 2, 1);
   g.addEdge(4, 3, 2);
   g.addEdge(4, 5, 2);
   g.addEdge(4, 6 ,4);
   g.addEdge(4, 8, 5);
   g.addEdge(5, 1, 3);
   g.addEdge(5, 2, 5);
   g.addEdge(5, 4, 2);
   g.addEdge(5, 8, 3);
   g.addEdge(6, 4, 4);
   g.addEdge(6, 7, 4);
   g.addEdge(6, 8, 1);
   g.addEdge(7, 3, 3);
   g.addEdge(7, 6, 4);
   g.addEdge(8, 4, 5);
   g.addEdge(8, 5, 3);
   g.addEdge(8, 6, 1);

   Prim(g, 1);

}