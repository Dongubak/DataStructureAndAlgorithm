#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>
#include <algorithm>
#include <cmath>

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
      bool isCommon = false;
      for(auto& edge: g[src]) {
         if(edge.dst == dst) {
            edge.weight = min(edge.weight, weight);
            isCommon = true;
            break;
         }
      }
      
      if(!isCommon) {
         g[src].emplace_back(Edge(dst, weight));
      }
   }
};

class Node {
public:
   int vertex;
   long sht;

   Node(int v, long s) : vertex(v), sht(s) {}

   bool operator>(const Node& other) const {
      return sht > other.sht;
   }
};

bool bellmanford(Graph& g, int st) {
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
            return true;
         }
      }
   }
   return false;

   // for(int i = 2; i < g.size; i++) {
   //    if(sht[i] == numeric_limits<long>::max()) {
   //       cout << -1 << '\n';
   //    } else {
   //       cout << sht[i] << '\n';
   //    }
   // }
}

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   int tn;
   cin >> tn;

   int vn, en, wn;

   for(int i = 0; i < tn; i++) {
      cin >> vn >> en >> wn;

      Graph g(vn);

      int s, d, w;

      for(int i = 0; i < en; i++) {
         cin >> s >> d >> w;

         g.addEdge(s, d, w);
         g.addEdge(d, s, w);
      }

      for(int i = 0; i < wn; i++) {
         cin >> s >> d >> w;
         g.addEdge(s, d, -w);
      }
      bool isCycled = false;
      for(int i = 1; i < g.size; i++) {
         if(isCycled = bellmanford(g, i)) {
            cout << "YES" << '\n';
            break;
         }
      }
      
      if(!isCycled) {
         cout << "NO" << '\n';
      }
   }



   return 0;
}