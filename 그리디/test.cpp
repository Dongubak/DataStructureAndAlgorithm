/*
1. 그래프의 모든 엣지를 최소 힙에 추가함
2. 모든 간선 중 가중치가 가장 작은 간선을 찾는다. (단, 기존에 삽입한 간선들로 인해 사이클이 발생하지 않아야 한다)
3. 찾은 간선을 트리에 추가한 후 엣지들의 집합이 공집합일때 까지 2단계를 반복 수행한다



*/

#include <iostream>
#include <vector>
#include <list>

class Edge {
public:
   int dst;
   int weight;

   Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   std::vector<std::list<Edge>> verticies;
   int size;

   Graph(int s) : size(s) {
      verticies.reserve(s);
   }

   void addEdge(int src, int dst, int weight) {
      verticies[src].push_front(Edge(dst, weight));
   }
};




int main(void) {
   using namespace std;

   Graph G(8);
   

   return 0;
}