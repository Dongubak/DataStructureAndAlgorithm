#include <bits/stdc++.h>
using namespace std;

int dp[45];

int main(void) {
   int n;
   cin >> n;

   dp[0] = 1; ///시작 1로 가는 경우의 수

   for(int i = 1; i <= n; i++) {
      if(i < 2) {
         dp[i] = 1;
      } else {
         dp[i] = dp[i - 1] + dp[i - 2];
      }
   }

   cout << dp[n];

   /*
      dp[2] -> 1칸 전에서 출발하거나 2칸전에서 출발하거나
      1. 한칸전에서 출발함
      dp[1]
      2. 두칸전에서 출발함
      dp[0] + 1이지만 해당안됨

      따라서 dp[2] = 1임
      
      dp[3] ->
      1. 한칸전에서 출발함
      dp[2]임
      2. 두칸 전에서 출발함
      dp[1]임

      ...

      dp[n] = dp[n - 1] + dp[n - 1] (단, n > 2)
      (n이 1인 경우엔 1이며 n이 2인 경우에도 1이다)
   */

   
   


   return 0;
}