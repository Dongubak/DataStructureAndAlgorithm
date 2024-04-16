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
   vector<vector<Edge>> g;
   int size;

   Graph(int s) : size(s) {
      g.resize(size + 1);
   }

   void addEdge(int src, int dst, int weight) {
      g[src].emplace_back(Edge(dst, weight));
   }
};

class Node {
public:
   int distance;
   int vertex;

   Node(int d, int v) : distance(d), vertex(v) {}

   bool operator>(const Node& other) const {
      return distance > other.distance;
   }
};

void track(int cur, int src, vector<int>& prev) {
   if(cur != src) {
      track(prev[cur], src, prev);
   }

   cout << cur << " ";
}

void dijkstra(const Graph& g, int st, int dst) {
   vector<int> sht(g.size + 1, numeric_limits<int>::max());
   vector<int> prev(g.size + 1, -1);

   std::priority_queue<Node, vector<Node>, greater<Node>> pq;
   sht[st] = 0;
   prev[st] = 0;

   pq.emplace(Node(0, st));

   while(!pq.empty()) {
      int cur = pq.top().vertex;
      pq.pop();

      for(const auto& edge: g.g[cur]) {
         if(sht[cur] + edge.weight < sht[edge.dst]) {
            sht[edge.dst] = sht[cur] + edge.weight;
            pq.emplace(Node(sht[edge.dst], edge.dst));
            prev[edge.dst] = cur;
         }
      }
   }

   track(dst, st, prev);

}


int main(void) {

   int vn, en;
   cin >> vn >> en;

   int s, d, w;

   Graph g(vn);
   for(int i = 0; i < en; i++) {
      cin >> s >> d >> w;
      g.addEdge(s, d, w);
      g.addEdge(d, s, w);
   }

   dijkstra(g, 1, 6);

   return 0;
}