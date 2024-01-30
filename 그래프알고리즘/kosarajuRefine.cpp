#include <cstdio>
#include <vector>
#include <stack>
#include <list>

class Edge {
public:
    int dst;
    int weight;

    Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   std::vector<std::list<Edge>> G;
   int size;

   Graph(int s) : size(s) {
      G.resize(s);
   }

   void addEdge(int s, int d, int w) {
      G[s].push_back(Edge(d, w));
   }

   Graph transp() {
      Graph ret(size);
      for (int i = 1; i < size; i++) {
         for (auto& adj : G[i]) {
               ret.addEdge(adj.dst, i, adj.weight);
         }
      }
      return ret;
   }
};

void DFS_for_seq_recursive(Graph& g, std::stack<int>& seq, std::vector<int>& visited, int cur) {
   visited[cur] = 1;

   for(auto& e: g.G[cur]) {
      if(visited[e.dst] == 0) {
         DFS_for_seq_recursive(g, seq, visited, e.dst);
      }
   }
   seq.push(cur);
}

std::stack<int> DFS_for_seq(Graph& g) {
   std::vector<int> visited(g.size, 0);
   std::stack<int> seq;
   for(int i = 1; i < g.size; i++) {
      if(visited[i] == 0) {
         DFS_for_seq_recursive(g, seq, visited, i);
      }
   }

   return seq;
}

void DFS_for_SCC_recursive(Graph& g, std::vector<int>& visited, int cur, std::vector<int>& cc) {
   visited[cur] = 1;
   cc.push_back(cur);

   for(auto& e: g.G[cur]) {
      if(visited[e.dst] == 0) {
         DFS_for_SCC_recursive(g, visited, e.dst, cc);
      }
   }
}

void DFS_for_SCC(Graph& g, std::stack<int>& seq) {
   std::vector<int> visited(g.size, 0);

   while(!seq.empty()) {
      std::vector<int> cc;
      if(visited[seq.top()] == 0) {
         DFS_for_SCC_recursive(g, visited, seq.top(), cc);
      }

      if(!cc.empty()) {
         for(auto& a: cc) {
            printf("%d ", a);
         }

         printf("\n");
      }

      seq.pop();
   }
}

void kosaraju(Graph& g) {
   std::stack<int> seq = DFS_for_seq(g);
   Graph tranp = g.transp();
   DFS_for_SCC(tranp, seq);
}

int main(void) {
   using namespace std;
   int vn, en;

   scanf("%d %d", &vn, &en);

   Graph g(vn + 1);

   int st, dst, weight;
   for (int i = 0; i < en; i++) {
      scanf("%d %d %d", &st, &dst, &weight);
      g.addEdge(st, dst, weight);
   }

   kosaraju(g);


   return 0;
}