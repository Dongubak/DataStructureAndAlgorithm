#include <cstdio>
#include <vector>
#include <list>
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

void bellmanFord(Graph& g) {
   std::vector<int> distance(g.size, std::numeric_limits<int>::max());
   distance[1] = 0;
   for(int j = 0; j < g.size - 2; j++) {
      for(int i = 1; i < g.size; i++) {
         for(auto& e : g.G[i]) {
            if(distance[i] != std::numeric_limits<int>::max() &&
               distance[i] + e.weight < distance[e.dst]
            ) {
               distance[e.dst] = distance[i] + e.weight;
            }
         }
      }
   }

   bool isCycled = false;

   for(int i = 1; i < g.size; i++) {
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
      printf("음수 사이클 존재!");
   } else {
      for(int i = 1; i < g.size; i++) {
         printf("%d : %d\n", i, distance[i]);
      }
   }
}

int main(void) {
   using namespace std;

   Graph g1(6);
   g1.addEdge(1, 2, 3);
   g1.addEdge(2, 3, 5);
   g1.addEdge(2, 4, 10);
   g1.addEdge(4, 3, -7);
   g1.addEdge(3, 5 , 2);


   bellmanFord(g1);

   Graph g2(7);
   g2.addEdge(1, 2, 3);
   g2.addEdge(2, 4, -8);
   g2.addEdge(3, 2, 3);
   g2.addEdge(4, 3, 3);
   g2.addEdge(3, 5, 2);
   g2.addEdge(5, 6, -1);
   g2.addEdge(6, 2, 8);

   bellmanFord(g2);

   return 0;
}