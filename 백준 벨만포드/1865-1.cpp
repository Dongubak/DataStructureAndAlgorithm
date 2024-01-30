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

void sol(Graph& g) {
   int isPos = false;
   std::vector<int> distance(g.size, 10e6);
   distance[1] = 0;
   for(int i = 0; i < g.size - 2; i++) {
      for(int j = 1; j < g.size; j++) {
         for(auto& edge: g.g[j]) {
            if(distance[j] != 10e6 &&
               distance[j] + edge.weight < distance[edge.dst]
            ) {
               distance[edge.dst] = distance[j] + edge.weight;
            }
         }
      }
   }

   bool isCycled = false;
   for(int j = 1; j < g.size; j++) {
      for(auto& edge: g.g[j]) {
         if(distance[j] != 10e6 &&
            distance[j] + edge.weight < distance[edge.dst]
         ) {
            isCycled = true;
            break;
         }
      }
      if(isCycled) {
         break;
      }
   }

   if(isCycled && distance[1] < 0) {
      isPos = true;
   }
   
   if(isPos) {
      printf("YES\n");
   } else {
      printf("NO\n");
   }

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

      for(int i = 0; i < wn; i++) {
         scanf("%d %d %d", &s, &d, &w);
         g.addEdge(s, d, w * -1);
      }

      sol(g);
   }

   return 0;
}