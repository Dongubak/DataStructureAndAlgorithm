#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>

using namespace std;

class Edge {
public:
   int dst;
   int weight;

   Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   vector<list<Edge>> g;
   int size;

   Graph(int s) : size(s + 1) {
      g.resize(s + 1);
   }

   void addEdge(int src, int dst, int weight) {
      g[src].emplace_back(Edge(dst, weight));
   }
};

class Node {
public:
   int vertex;
   int sht;

   Node(int v, int s) : vertex(v), sht(s) {}

   bool operator>(const Node& other) const {
      return sht > other.sht;
   }
};

void bellmanford(Graph& g, int st) {
   vector<long> sht(g.size, numeric_limits<long>::max());
   sht[st] = 0;
   
   bool isUpdated;

   // g.size -> v + 1
   for(int i = 0; i < g.size - 2; i++) {
      isUpdated = false;
      for(int j = 1; j < g.size; j++) {
         if(sht[j] == numeric_limits<long>::max()) {
            continue;
         }
         for(const auto& edge: g.g[j]) {
            if(sht[j] + edge.weight < sht[edge.dst]) {
               sht[edge.dst] = sht[j] + edge.weight;
               isUpdated = true;
            }
         }
      }

      if(!isUpdated) {
         break;
      }
   } 

   for(int i = 1; i < g.size; i++) {
      if(sht[i] == numeric_limits<long>::max()) {
         continue;
      }

      for(const auto& edge: g.g[i]) {
         if(sht[i] + edge.weight < sht[edge.dst]) {
            cout << -1;
            return;
         }
      }
   }
   

   for(int i = 2; i < g.size; i++) {
      if(sht[i] == numeric_limits<long>::max()) {
         cout << -1 << '\n';
      } else {
         cout << sht[i] << '\n';
      }
   }
}

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   int vn, en, st;
   cin >> vn >> en;

   st = 1;
   Graph g(vn);

   int s, d, w;

   for(int i = 0; i < en; i++) {
      cin >> s >> d >> w;

      g.addEdge(s, d, w);
   }

   bellmanford(g, st);

   return 0;
}