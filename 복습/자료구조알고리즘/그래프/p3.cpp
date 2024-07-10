#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::set;
using std::queue;
using std::pair;
using std::endl;


class Graph {
public:
   vector<set<int>> g;

   Graph(int size) {
      g.resize(size);
   }

   void addEdge(int src, int dst) {
      g[src].emplace(dst);
      g[dst].emplace(src);
   }
};

void sol(Graph& g, int st, int t) { ///st에서 인접한거 하나만 골라서 BFS탐색하고 가중치의 최대값 구함
   int vn = g.g.size();
   // cout << vn << '\n';
   int finish = *g.g[st].begin();
   // cout << finish << '\n';

   vector<int> vis(vn);
   queue<pair<int, int>> q; q.push({st, 0}); vis[st] = 1; ///queue에는 정점과 거까지 가는데 거리를 저장함

   int maxSum = 0;

   while(!q.empty()) {
      int qsize = q.size();

      for(int i = 0; i < q.size(); i++) { /// i는 횟수임; 건들 ㄴㄴ
         pair<int, int> p = q.front(); q.pop();
         auto& [src, weight] = p;

         for(auto dst: g.g[src]) { /// dst는 인접한 정점임
            if(!vis[dst]) { /// 노 방문
               // cout << src << " " << dst << " " << weight << '\n';
               vis[dst] = 1;
               if(dst != finish) {
                  q.push({dst, weight + 1});
               }
            } else {
               if(dst == finish) {
                  maxSum = std::max(maxSum, weight + 1);
               }
            }

         }
      }
   }
   // cout << maxSum << " " << vn - maxSum << '\n';
   long long res = (long long)(maxSum) * (maxSum - 1) / 2 + (vn - maxSum - 1) * (vn - maxSum - 2) / 2;
   cout << "Case #" << t + 1 << endl << res << endl;
}

int main(void) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(NULL);
   int c;
   cin >> c;

   for(int p = 0; p < c; p++) {
      int vn, en;
      cin >> vn;
      en = vn + 1;

      Graph g(vn + 1);

      for(int i = 0; i < en; i++) {
         int st, dst;
         cin >> st >> dst;

         g.addEdge(st, dst);
      }
      
      bool isTripleEdge = false;

      for(int i = 1; i <= vn; i++) {
         if(g.g[i].size() == 3) {
            isTripleEdge = true;
            sol(g, i, p);
            break;
         }
      }

      if(!isTripleEdge) {
         long long res = (long long)(vn - 1) * (vn - 2) / 2;
         cout << "Case #" << p + 1 << endl << res << endl;
      }
   }
   

   return 0;
}