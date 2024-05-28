#include <iostream>
using namespace std;

int st[300 + 1];
int dp[300 + 1][3];

int main(void) {
   int n;
   cin >> n;

   for(int i = 1; i <= n; i++) {
      cin >> st[i];
   }

   dp[1][1] = st[1];
   dp[2][1] = st[2];

   for(int i = 1; i <= n; i++) {
      dp[i + 1][2] = dp[i][1] + st[i + 1];
      dp[i + 2][1] = max(dp[i][1], dp[i][2]) + st[i + 2];
   }

   cout << max(dp[n][1], dp[n][2]);

   return 0;
}