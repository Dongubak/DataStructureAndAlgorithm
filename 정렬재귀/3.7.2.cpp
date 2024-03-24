#include <bits/stdc++.h>

using namespace std;

int dp[6 + 1];

class Edge {
public:
   int dst;
   Edge(int d) : dst(d) {}
};

class Graph {
public:
   vector<list<Edge>> g;

   Graph(int n) {
      g.resize(n);
   }

   void addEdge(int s, int d) {
      g[s].push_back(Edge(d));
   }
};

int main(void) {
   int vn, en;
   cin >> vn >> en;

   Graph g(vn);
   int s, d;

   for(int i = 0; i < en; i++) {
      cin >> s >> d;
      g.addEdge(s, d);
   }

   dp[0] = 0;

   for(int i = 0; i < vn; i++) {
       
   }
   

   return 0;
}