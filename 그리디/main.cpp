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
      unsigned int parent; ///부모에 대한 정보를 저장한다.

      Node(unsigned _id) : id(_id), rank(0), parent(_id) {} ///랭크는 0으로 초기화

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
      nodes.emplace_back(x); ////????
   }

   unsigned find(unsigned x) { ///finding node's parent
      auto node_it = find_if(nodes.begin(), nodes.end(), [x](Node n) {
         return n.id == x;
      });

      unsigned node_id = (*node_it).id;

      while(node_id != nodes[node_id].parent) {
         node_id = nodes[node_id].parent;
      }

      return node_id; ///루트노드의 아이디를 얻어서 반환한다.
   }

   void union_sets(unsigned x, unsigned y) {
      auto root_x = find(x); ///x의 루트노드
      auto root_y = find(y); ///y의 루트노드

      if(root_x == root_y) { ///같으면 병합 불가
         return;
      }

      if(nodes[root_x].rank > nodes[root_y].rank) { ///다르다면 랭크가 큰 루트 노드를 y에 할당함
         swap(root_x, root_y);
      }
      
      nodes[root_x].parent = nodes[root_y].parent; ///y가 부모가 되어 x를 y아래로 삽입함
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