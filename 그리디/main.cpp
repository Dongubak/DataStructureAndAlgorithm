#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class SimpleDisjointSet {
private:
   struct Node {
      unsigned int id;
      unsigned int rank;
      unsigned int parent;

      Node(unsigned _id) : id(_id), rank(0), parent(_id) {}

      bool operator != (const Node& n) const {
         return this->id != n.id;
      }
   };

   vector<Node> nodes;

public:
   SimpleDisjointSet(unsigned N) {
      nodes.reserve(N);
   }

   void make_set(const unsigned& x) {
      nodes.emplace_back(x);
   }

   unsigned find(unsigned x) {
      auto node_it = find_if(nodes.begin(), nodes.end(), [x](Node n) {
         return n.id == x;
      });

      unsigned node_id = (*node_it).id;

      while(node_id != nodes[node_id].parent) {
         node_id = nodes[node_id].parent;
      }

      return node_id;
   }

   void union_sets(unsigned x, unsigned y) {
      auto root_x = find(x);
      auto root_y = find(y);

      if(root_x == root_y) {
         return;
      }

      if(nodes[root_x].rank > nodes[root_y].rank) {
         swap(root_x, root_y);
      }

      nodes[root_x].parent = nodes[root_y].parent;
      nodes[root_y].rank++;
   }
};

template <typename T>
struct Edge {
   unsigned src;
   unsigned dst;
   T weight;

   inline bool operator<(const Edge<T>& e) const {
      return this->weight < e.weight;
   }

   inline bool operator> (const Edge<T>& e) const { ///edge간의 비교는 가중치끼리의 비교이다.
      return this->weight > e.weight;
   }
};

template<typename T>
class Graph {
public:
   Graph(unsigned N) : V(N) {}

   auto vertices() const {
      return V;
   }

   auto& edges() const {
      return edge_list;
   }

   auto edges(unsigned v) const {
      vector<Edge<T>> edges_from_v;
      for(auto& e : edge_list) {
         if(e.src == v) {
            edges_from_v.emplace_back(e);
         }
      }
      return edges_from_v;
   }

void add_edge(Edge<T>&& e) {
   
}
};