#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::endl;

void sol(int n) {
   int vn;
   cin >> vn;

   vector<vector<int>> g(vn + 1, vector<int>(vn + 1, 0));
   
   for(int i = 0; i < vn + 1; i++) {
      int src, dst;
      cin >> src >> dst;

      g[src][dst] = 1; g[src][0] += 1;
      g[dst][src] = 1; g[dst][0] += 1;
   }

   vector<int> triple(2, 0);
   int c = 0;

   for(int i = 1; i < vn + 1; i++) {
      if(g[i][0] == 3) {
         triple[c++] = i;
      }
   }

   g[triple[0]][triple[1]] = 0;
   g[triple[1]][triple[0]] = 0;

   
   int destination = triple[0];
   int current = triple[1];

   vector<int> vis(vn + 1);
   int count = 0;
   vis[current] = 1;

   while(1) {
      for(int j = 1; j < vn + 1; j++) {
         if(g[current][j] && !vis[j]) {
            if(j == destination) {
               count += 1;
               long long res = (long long)count * (count - 1) / 2 + (long long)(vn - count) * (vn - count - 1) / 2;
               cout << "Case #" << n << endl << res << endl;
               return;
            } else {
               vis[j] = 1;
               current = j;
               ++count;
            }
            break;
         }
      }
   }
}

int main(void) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(NULL);
   int c;

   cin >> c;

   for(int i = 0; i < c; i++) {
      sol(i + 1);
   }

   return 0;
}