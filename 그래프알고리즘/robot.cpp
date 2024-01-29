#include <iostream>
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
   std::vector<int> distance(g.size, std::numeric_limits<int>::min());
   distance[0] = 0;
   
   for(int j = 0; j < g.size - 1; j++) {
      for(int i = 0; i < g.size; i++) {
         for(auto& e : g.G[i]) {
            if(distance[i] != std::numeric_limits<int>::min() &&
               distance[i] + e.weight > distance[e.dst]
            ) {
               distance[e.dst] = distance[i] + e.weight;
            }
         }
      }
   }

   bool isCycled = false;

   for(int i = 0; i < g.size; i++) {
      for(auto& e : g.G[i]) {
         if(distance[i] != std::numeric_limits<int>::min() &&
            distance[i] + e.weight > distance[e.dst]
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
      std::cout << "탐색 중단";
   } else {
      std::cout << distance[g.size - 1];
   }
   
   
}

int main(void) {
   using namespace std;

   int N; ///가로 세로 길이
   string tmp;
   int tw;

   cin >> N;

   Graph g(N * N);

   
   
   for(int i = 0; i < N * N - 1; i++) {
      cin >> tmp >> tw;
      
      while(tmp != "") {
         switch(tmp.back()) {
            case 'N':
               g.addEdge(i, i - N, tw);
               break;
            case 'S':
               g.addEdge(i, i + N, tw);
               break;
            case 'E':
               g.addEdge(i, i + 1, tw);
               break;
            case 'W':
               g.addEdge(i, i - 1, tw);
               break;
         }
         tmp.pop_back();
      }
   }

   bellmanFord(g);


   return 0;
}