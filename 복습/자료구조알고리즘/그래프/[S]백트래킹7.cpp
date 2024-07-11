#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

int N, M;

vector<int> n;
vector<int> sel;

void rec(vector<int> vis, int s) {
   if(s >= M) {
      for(auto a: sel) {
         cout << a << " ";
      }
      cout << '\n';

      return;
   }

   for(int i = 0; i < N; i++) {
      if(!vis[i]) {
         vis[i] = 1; sel[s] = n[i];
         rec(vis, s + 1);
         vis[i] = 0;
      }
   }
}

int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> N >> M;

   n.resize(N);
   sel.resize(M);

   for(int i = 0; i < N; i++) {
      cin >> n[i];
   }

   sort(n.begin(), n.end());

   rec(vector<int>(N, 0), 0);

   return 0;
}