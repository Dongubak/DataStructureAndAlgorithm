#include <iostream>
using namespace std;

long long dp[100 + 1];

int main(void) {
   int n, N, l = 0;
   cin >> n;
   dp[1] = 1;
   dp[2] = 1;
   dp[3] = 1;
   for(int i = 0; i < n; i++) {
      cin >> N;
      if(N > l) {
         for(int j = 4; j <= N; j++) {
            dp[j] = dp[j - 2] + dp[j - 3];
         }
         l = N;
      }
      cout << dp[N] << '\n';
   }
}