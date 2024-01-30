#include <cstdio>
#include <vector>
#include <list>
#include <numeric>
#include <queue>

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

std::vector<int> bellmanFord(Graph& g, int st) {
   std::vector<int> distance(g.size, std::numeric_limits<int>::max());
   distance[0] = 0;
   distance[st] = 0; 
   for(int j = 0; j < g.size; j++) {
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

   for(int i = 0; i < g.size - 1; i++) {
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

   return distance;
}

std::vector<int> dijkstra(int vn, int st, const Graph& g) {
   std::vector<int> sht(vn, std::numeric_limits<int>::max());
   std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

   sht[st] = 0;
   pq.push(std::make_pair(0, st));

   while (!pq.empty()) {
      int mv = pq.top().second;
      pq.pop();
      for (const auto& edge : g.G[mv]) {
         if (sht[mv] != std::numeric_limits<int>::max() &&
             sht[mv] + edge.weight < sht[edge.dst]) {
            sht[edge.dst] = sht[mv] + edge.weight;
            pq.push(std::make_pair(sht[edge.dst], edge.dst));
         }
      }
   }

   return sht;
}

void Johnson(Graph& g) {
   Graph g1 = g;
   Graph g2 = g;
   Graph g3 = g;
   Graph g4 = g;
   Graph g5 = g;

   std::vector<int> distance1 = bellmanFord(g1, 1);
   std::vector<int> distance2 = bellmanFord(g2, 2);
   std::vector<int> distance3 = bellmanFord(g3, 3);
   std::vector<int> distance4 = bellmanFord(g4, 4);
   std::vector<int> distance5 = bellmanFord(g5, 5);

   for (int i = 1; i < g1.size; i++) {
      for (auto& e : g1.G[i]) {
         e.weight += distance1[i] - distance1[e.dst];
      }
   }

   std::vector<int> sht = dijkstra(g1.size, 1, g1);

   for(int i = 1; i < g1.size; i++) {
      printf("%d %d\n", i, sht[i] + distance1[i]);
   }


   for (int i = 1; i < g2.size; i++) {
      for (auto& e : g2.G[i]) {
         e.weight += distance2[i] - distance2[e.dst];
      }
   }

   sht = dijkstra(g2.size, 2, g2);

   for(int i = 1; i < g2.size; i++) {
      printf("%d %d\n", i, sht[i] + distance2[i]);
   }

   for (int i = 1; i < g3.size; i++) {
      for (auto& e : g3.G[i]) {
         e.weight += distance3[i] - distance3[e.dst];
      }
   }

   sht = dijkstra(g3.size, 3, g3);

   for(int i = 1; i < g3.size; i++) {
      printf("%d %d\n", i, sht[i] + distance3[i]);
   }

   for (int i = 1; i < g4.size; i++) {
      for (auto& e : g4.G[i]) {
         e.weight += distance4[i] - distance4[e.dst];
      }
   }

   sht = dijkstra(g4.size, 4, g4);

   for(int i = 1; i < g4.size; i++) {
      printf("%d %d\n", i, sht[i] + distance4[i]);
   }

   for (int i = 1; i < g5.size; i++) {
      for (auto& e : g5.G[i]) {
         e.weight += distance5[i] - distance5[e.dst];
      }
   }

   sht = dijkstra(g1.size, 5, g5);

   for(int i = 1; i < g5.size; i++) {
      printf("%d %d\n", i, sht[i] + distance5[i]);
   }
}

int main(void) {
   using namespace std;

   Graph g1(6);
   g1.addEdge(1, 2, -7);
   g1.addEdge(2, 3, -2);
   g1.addEdge(3, 1, 10);
   g1.addEdge(1, 4, -5);
   g1.addEdge(1, 5, 2);
   g1.addEdge(4, 5, 4);
   g1.addEdge(0, 1, 0);
   g1.addEdge(0, 2, 0);
   g1.addEdge(0, 3, 0);
   g1.addEdge(0, 4, 0);
   g1.addEdge(0, 5, 0);

   Johnson(g1);


   return 0;
}