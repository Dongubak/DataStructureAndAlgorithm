#include <iostream>
using namespace std;

int dp[500 + 1][500 + 1];
int tree[500 + 1][500 + 1];

int main(void) {
   int n;
   cin >> n;

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < i + 1; j++) {
         cin >> tree[i + 1][j + 1];
      }
   }

   dp[1][1] = tree[1][1];

   for(int i = 2; i <= n; i++) {
      for(int j = 1; j <= i; j++) {
         dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + tree[i][j];
      }
   }

   int tmpMax = dp[n][1];
   for(int i = 2; i <= n; i++) {
      tmpMax = dp[n][i] > tmpMax ? dp[n][i] : tmpMax;
   }

   cout << tmpMax;

   return 0;
}