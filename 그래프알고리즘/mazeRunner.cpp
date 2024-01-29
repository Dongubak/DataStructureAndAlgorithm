#include <cstdio>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <stack>
#include <set>

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

   Graph transp() {
      Graph ret(size);
      for (int i = 0; i < size; i++) {
         for (auto& adj : G[i]) {
               ret.addEdge(adj.dst, i, adj.weight);
         }
      }
      return ret;
   }
};


void mazeRunner(Graph& g) {
   bool isCycled = false;
   std::vector<int> score(g.size, std::numeric_limits<int>::max());
   for(int i = 0; i < g.size; i++) {
      std::vector<int> distance(g.size, std::numeric_limits<int>::max());
      distance[i] = 0;
      for(int j = 0; j < g.size - 1; j++) {
         for(int i = 0; i < g.size; i++) {
            for(auto& e : g.G[i]) {
               if(distance[i] != std::numeric_limits<int>::max() &&
                  distance[i] + e.weight < distance[e.dst]
               ) {
                  distance[e.dst] = distance[i] + e.weight;
               }
            }
         }
      }

      for(int i = 0; i < g.size; i++) {
         for(auto& e : g.G[i]) {
            if(distance[i] != std::numeric_limits<int>::max() &&
               distance[i] + e.weight < distance[e.dst]
            ) {
               isCycled = true;
               break;
            }
         }
         if(isCycled) {
            break;
         }
      }
      
      if(isCycled) {
         printf("유효하지 않은 미로");
         return;
      } else {
         int tmp = std::numeric_limits<int>::max();
         for(auto& a: distance) {
            if(a != 0) {
               tmp = a < tmp ? a : tmp;
            }
         }

         score[i] = tmp;
      }
   }
   for(int i = 0; i < g.size; i++) {
      if(score[i] == std::numeric_limits<int>::max()) {
         printf("%d: 고립된 방\n", i);
      } else {
         printf("%d: %d\n", i, score[i]);
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

   mazeRunner(g);

   // Graph tr_g = g.transp();

   // std::stack<int> seq = DFS(g);

   // kosaraju(seq, tr_g);

   return 0;
}