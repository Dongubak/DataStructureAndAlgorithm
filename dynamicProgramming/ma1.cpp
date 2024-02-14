#include <bits/stdc++.h>

using namespace std;

// int memo[100];

// int fib(int n) {
//    if(n < 2) {
//       return n;
//    }

//    if(memo[n] != -1) { ///n값이 있는 경우
//       return memo[n];
//    }
//    int res = fib(n - 1) + fib(n - 2);
//    memo[n] = res;

//    return res;
// }

int dp[101];

int fib(int n) {
   dp[1] = 1;

   for(int i = 2; i < n + 1; i++) {
      dp[i] = dp[i - 2] + dp[i - 1];
   }

   return dp[n];
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   memset(dp, 0, sizeof(dp));


   // memset(memo, -1, sizeof(memo));

   // cout << fib(5);

   cout << fib(5);
   
   return 0;
}