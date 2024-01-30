#include <cstdio>
#include <vector>
#include <list>

class Edge {
public:
   int dst;
   int weight; 

   Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   int size;
   std::vector<std::list<Edge>> g;
   Graph(int s) : size(s) {
      g.resize(s);
   }

   void addEdge(int s, int d, int w) {
      g[s].push_back(Edge(d, w));
   }
};

bool sol(Graph& g) {
   int isPos = false;
   std::vector<int> distance(g.size, 0x7f);
   distance[1] = 0;
   for(int i = 0; i < g.size; i++) { 
      for(int j = 1; j < g.size; j++) {
         for(Edge& edge: g.g[j]) {
            if(distance[j] != 0x7f &&
               distance[j] + edge.weight < distance[edge.dst]
            ) {
               if(i == g.size - 1 && distance[1] != 0) {
                  return true;
               }
               distance[edge.dst] = distance[j] + edge.weight;
            }
         }
      }
   }
   return false;
}

int main(void) {
   int tc;
   scanf("%d", &tc);
   for(int i = 0; i < tc; i++) {
      int vn, en, wn;
      int s, d, w;
      scanf("%d %d %d", &vn, &en, &wn);

      Graph g(vn + 1);
   
      for(int i = 0; i < en; i++) {
         scanf("%d %d %d", &s, &d, &w);
         g.addEdge(s, d, w);
         g.addEdge(d, s, w);
      }
      bool isPos = false;
      for(int i = 0; i < wn; i++) {
         scanf("%d %d %d", &s, &d, &w);
         g.addEdge(s, d, w * -1);
      }
      if(sol(g)) {
         printf("YES\n");
      } else {
         printf("NO\n");
      }
   }

   return 0;
}