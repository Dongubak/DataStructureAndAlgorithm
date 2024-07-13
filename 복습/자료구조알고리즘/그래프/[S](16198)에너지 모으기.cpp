#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

int N;
vector<int> W;
vector<int> vis;
int max;

void rec(int n, int e) {
   if(n >= N - 2) { ///종료
      max = std::max(e, max);
      return;
   }

   for(int i = 1; i < N - 1; i++) {
      if(!vis[i]) {
         vis[i] = 1;
         int j = i - 1, k = i + 1;

         while(vis[j]) {
            j -= 1;
         }

         while(vis[k]) {
            k += 1;
         }
         rec(n + 1, e + W[j] * W[k]);
         vis[i] = 0;
      }
   }
}


int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   cin >> N;

   W.resize(N);
   vis.resize(N, 0);

   for(int i = 0; i < N; i++) {
      cin >> W[i];
   }

   rec(0, 0);

   cout << max;

   return 0;
}