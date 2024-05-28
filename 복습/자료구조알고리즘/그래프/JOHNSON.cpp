#include <iostream>
#include <vector>
#include <list>

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

   void addEdge(int s, int d, int w) {
      g[s].emplace_back(Edge(d, w));
   }
};

int main(void) {
   


   return 0;
}