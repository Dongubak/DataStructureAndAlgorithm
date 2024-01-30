#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>

class Edge {
public:
   int dst;
   int weight;

   Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   int size;
   std::vector<std::list<Edge>> g;

   Graph(int s) : size(s) {
      g.resize(size);
   }

   void addEdge(int s, int d, int w) {
      g[s].push_front(Edge(d, w));
   }
};

bool DFS_Recursive(std::vector<int>& prev, int cur, int st, std::vector<int>& visited) {
   visited[cur] = 1;
   if(cur == st) {
      return true;
   }

   if(visited[prev[cur]] == 0) {
      return DFS_Recursive(prev, prev[cur], st, visited);
   }
}

bool DFS(std::vector<int>& prev, int end, int st) {
   std::vector<int> visited(prev.size(), 0);
   return DFS_Recursive(prev, end, st, visited);
}

void sol(Graph& g, int s, int e, std::vector<int>& earn) {
   std::vector<long long> distance(g.size, -10000000000);
   std::vector<int> prev(g.size, -1);
   distance[s] = earn[s];
   prev[s] = s;
   
   for(int i = 0; i < g.size - 1; i++) {
      for(int j = 0; j < g.size; j++) {
         for(auto& edge: g.g[j]) {
            if(distance[j] != -10000000000 &&
            distance[j] + edge.weight > distance[edge.dst]) {
               prev[edge.dst] = j;
               distance[edge.dst] = distance[j] + edge.weight;
            }
         }
      }
   }

   bool isCycled = false;

   for(int i = 0; i < g.size; i++) {
      for(auto& edge: g.g[i]) {
         if(distance[edge.dst] != -10000000000 &&
         distance[i] + edge.weight > distance[edge.dst]) {
            distance[edge.dst] = distance[i] + edge.weight;
            isCycled = true;
            break;
         }
      }
   }


   if(distance[e] == -10000000000) {
      printf("gg");
   } else if(isCycled) {
      // if(DFS(prev, e, s)) {
      //    std::vector<int> v;
      //    int cur = e;
      //    while(cur != s) {
      //       v.push_back(cur);
      //       cur = prev[cur];
      //    }
      //    v.push_back(s);
      //    bool isPos = true;
      //    for(int i = 0; i < g.size; i++) {
      //       for(auto& edge: g.g[i]) {
      //          if(distance[edge.dst] != -10000000000 &&
      //          distance[i] + edge.weight > distance[edge.dst]) {
      //             distance[edge.dst] = distance[i] + edge.weight;
      //             if(std::find(v.begin(), v.end(), edge.dst) != v.end()) {
      //                isPos = false;
      //                break;
      //             }
      //          }
      //       }
      //       if(!isPos) {
      //          break;
      //       }
      //    }
      //    if(isPos) {
      //       printf("%lld", distance[e]);
      //    } else {
      //       printf("Gee");
      //    }
      printf("Gee");
      // } else {
      //    printf("Gee");
      // }
   } else {
      printf("%lld", distance[e]);
   }
}

int main(void) {

   int vn, en;
   int st, end;
   int s, d, w;
   
   scanf("%d %d %d %d", &vn, &st, &end, &en);

   Graph g(vn);

   for(int i = 0; i < en; i++) {
      scanf("%d %d %d", &s, &d, &w);
      g.addEdge(s, d, w * -1);
   }

   std::vector<int> earn(vn);
   int tmp;
   for(int i = 0; i < vn; i++) {
      scanf("%d", &tmp);
      earn[i] = tmp;
   }

   for(int i = 0; i < g.size; i++) {
      for(auto& e: g.g[i]) {
         e.weight += earn[e.dst];
      }
   }

   sol(g, st, end, earn);

   return 0;
}