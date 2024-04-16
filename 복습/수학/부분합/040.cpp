#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
   int n;
   cin >> n;

   vector<int> d(n); ///n - 1
   for(int i = 1; i < n; i++) {
      cin >> d[i];
   }

   for(int i = 1; i < n; i++) {
      d[i] = d[i - 1] + d[i];
   }

   int m, cur, b, ans = 0;
   cin >> m >> b;
   cur = b;

   for(int i = 0; i < m; i++) {
      cin >> b;
      ans += abs(d[cur - 1] - d[b - 1]);
      cur = b;
   }

   cout << ans;

   return 0;
}