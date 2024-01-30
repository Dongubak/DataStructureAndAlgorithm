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
      g.resize(size);
   }

   void addEdge(int s, int d, int w) {
      g[s].push_front(Edge(d, w));
   }
};

void sol(Graph& g) {
   std::vector<long long> distance(g.size, 9223372036854775807LL);

   distance[1] = 0;

   for(int i = 0; i < g.size - 2; i++) {
      for(int j = 1; j < g.size; j++) {
         for(auto& e: g.g[j]) {
            if(distance[j] != 9223372036854775807LL &&
             distance[j] + e.weight < distance[e.dst]) {
               distance[e.dst] = distance[j] + e.weight;
            }
         }
      }
   }

   bool isCycled = false;
   for(int i = 1; i < g.size; i++) {
      for(auto& e: g.g[i]) {
         if(distance[e.dst] != 9223372036854775807LL &&
          distance[i] + e.weight < distance[e.dst]) {
            isCycled = true;
            break;
         }
      }

      if(isCycled) {
         break;
      } 
   }

   if(isCycled) {
      printf("-1");
   } else {
      for(int i = 2; i < g.size; i++) {
         printf("%lld\n", distance[i] == 9223372036854775807LL ? -1 : distance[i]);
      }
   }
}

int main(void) {

   int vn, en;
   int s, d, w;
   scanf("%d %d", &vn, &en);

   Graph g(vn + 1);

   for(int i = 0; i < en; i++) {
      scanf("%d %d %d", &s, &d, &w);
      g.addEdge(s, d, w);
   }

   sol(g);

   return 0;
}