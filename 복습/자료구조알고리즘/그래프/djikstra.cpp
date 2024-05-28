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

   bool operator<(const Node& other) const {
      return sht < other.sht;
   }
};

void dijstra(Graph& g, int st) {
   vector<int> sht(g.size, numeric_limits<int>::max());
   sht[st] = 0;

   priority_queue<Node, vector<Node>, greater<Node>> pq;
   pq.push(Node(st, 0));

   while(!pq.empty()) {
      
      int cur = pq.top().vertex;
      int we = pq.top().sht;

      pq.pop();

      if(we != sht[cur]) {
         continue;
      } ///꺼낸 정점의 최단거리 값과 최단거리표의 정점의 값이 다른 경우

      

      for(const auto& edge: g.g[cur]) {
         if(sht[cur] + edge.weight < sht[edge.dst]) {
            sht[edge.dst] = sht[cur] + edge.weight;
            pq.emplace(Node(edge.dst, sht[edge.dst]));
         }
      }
   }

   for(int i = 1; i < g.size; i++) {
      if(sht[i] == numeric_limits<int>::max()) {
         cout << "INF" << '\n';
      } else {
         cout << sht[i] << '\n';
      }
   }
}

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   int vn, en, st;
   cin >> vn >> en >> st;
   Graph g(vn);

   int s, d, w;

   for(int i = 0; i < en; i++) {
      cin >> s >> d >> w;

      g.addEdge(s, d, w);
   }

   dijstra(g, st);

   return 0;
}