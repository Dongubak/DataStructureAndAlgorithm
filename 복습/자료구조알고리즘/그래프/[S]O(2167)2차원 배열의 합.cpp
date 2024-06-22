#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<vector<int>> s;

int main(void) {

   int n, m;
   cin >> n >> m;
   s.resize(n);
   for(int i = 0; i < n; i++) {
      s[i].resize(m);
      for(int j = 0; j < m; j++) {
         cin >> s[i][j];
      }
   }

   int k;
   cin >> k;

   int p, q, x, y;

   for(int l = 0; l < k; l++) {
      int sum = 0;
      cin >> p >> q >> x >> y;
      p -= 1, q -= 1, x -= 1, y -= 1;
      
      for(int i = p; i <= x; i++) {
         for(int j = q; j <= y; j++) {
            sum += s[i][j];
         }
      }

      cout << sum << '\n';
   }


   return 0;
}