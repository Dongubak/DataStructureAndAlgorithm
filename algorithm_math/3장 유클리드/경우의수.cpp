#include <bits/stdc++.h>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, t;
   cin >> n;

   int c[3] {}; ///0 -> 1의 개수
             ///1 -> 2의 개수
             ///2 -> 3의 개수

   for(int i = 0; i < n; i++) {
      cin >> t;
      c[t - 1] += 1;
   }

   int res = 0;
   for(int i = 0; i < 3; i++) {
      res += (c[i] * (c[i] - 1) / 2);
   }

   cout << res;

   return 0;
}