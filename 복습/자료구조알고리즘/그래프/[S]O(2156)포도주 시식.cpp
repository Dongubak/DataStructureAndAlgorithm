#include <iostream>
using namespace std;

int dp[10000 + 1][3];
int g[10000 + 1];

int gm;

int main(void) {
   int n;
   cin >> n;

   for(int i = 1; i <= n; i++) {
      cin >> g[i];
   }

   for(int i = 1; i <= n; i++) {
      dp[i][1] = max(dp[i][1], g[i]);

      int tm = max(dp[i][1], dp[i][2]);
      int j = 2;

      while(i + j <= n) {
         dp[i + j][1] = max(tm + g[i + j], dp[i + j][1]);
         j++;
      }

      if(i + 1 <= n) {
         dp[i + 1][2] = dp[i][1] + g[i + 1];
      }

      gm = tm > gm ? tm : gm;
   }

   cout << gm;

   return 0;
}