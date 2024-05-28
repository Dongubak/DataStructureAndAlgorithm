#include <iostream>
using namespace std;

long long dp[30 + 1][30 + 1];

int main(void) {
   int t;
   cin >> t;
   dp[1][1] = 1;
   for(int i = 2; i <= 30; i++) {
      dp[i][1] = i;

      for(int j = 1; j < i - 1; j++) {
         dp[i][j + 1] = dp[i - 1][j] + dp[i - 1][j + 1];
      }

      dp[i][i] = 1;
   }

   for(int i = 0; i < t; i++) {
      int r, n;
      cin >> r >> n;

      cout << dp[n][r] << '\n';
   }

   return 0;
}