#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];

int main(void) {
   int n, m;

   cin >> n >> m;

   vector<int> values(n);
   vector<int> weights(n);

   int v, w;

   for(int i = 0; i < n; i++) {
      cin >> w >> v;
      weights[i] = w;
      values[i] = v;
   }

   dp[0][0] = 0;

   for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= m; j++) {
         dp[i][j] = dp[i - 1][j];

         if(j - weights[i - 1] >= 0) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
         }
      }
   }

   int tmpMax = dp[n][0];

   for(int i = 1; i <= m; i++) {
      tmpMax = dp[n][i] > tmpMax ? dp[n][i] : tmpMax;
   }

   cout << tmpMax;

   return 0;
}