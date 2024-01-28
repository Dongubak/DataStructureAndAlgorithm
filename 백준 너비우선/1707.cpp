#include <cstdio>
#include <vector>
#include <list>

class Graph {
public:
   std::vector<std::list<std::pair<int, int>>> G;

   Graph(int size) {
      G.resize(size);
   }

   void addEdge(int src, int dst) {
      G[src].push_front({dst, -1});
   }
};

void DFS(Graph& G, int vn) {
   std::vector<bool> visited(vn + 1, false); 
   DFS_Recursive(G, 1, visited, true);
}

void DFS_Recursive(Graph& G, int v, std::vector<bool>& visited, bool c) {
   visited[v] = true;
   G.G[v] = c ? false : true;
   for(auto v : G.G[v]) {

   }
}

int main(void) {
   using namespace std;
   
   int vn, en;
   int st, end;
   scanf("%d %d", &vn, &en);
   Graph G(vn + 1);
   for(int i = 0; i < en; i++) {
      scanf("%d %d", &st, &end);
      G.addEdge(st, end);
   }

   DFS(G, vn);


   return 0;
}