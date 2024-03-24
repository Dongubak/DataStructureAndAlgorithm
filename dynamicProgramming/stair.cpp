#include <bits/stdc++.h>
using namespace std;

int dp[301][2];

int main(void) {

   int n;
   cin >> n;

   vector<int> stair(n);

   for(int i = 0 ; i < n; i++) {
      cin >> stair[i];
   }

   dp[0][0] = 0;
   dp[0][1] = 0;

   ///first : 점수 second: 연속 넘은 계단 수

   for(int i = 1; i <= 2; i++) {
      dp[i][0] = dp[i - 1][0] + stair[i - 1];
      dp[i][1] = dp[i - 1][1] + 1;
      cout << dp[i][0] << " ";
   }

   for(int i = 3; i <= n; i++) {
         
         if(i == 3) {
            if(stair[i - 2] + stair[i - 1] > stair[i - 3] + stair[i - 1]) { ///0번째 칸 에서 2번째 칸이동후 3번째 칸
               dp[i][0] = stair[i - 2] + stair[i - 1];
               dp[i][1] = 2;
            } else { ///1번째 칸에서 3번째 칸 이동
               dp[i][0] = stair[i - 3] + stair[i - 1];
               dp[i][1] = 1;
            }
         } else {
            if(dp[i - 1][1] == 2) {
            dp[i][0] = dp[i - 2][0] + stair[i - 1];
            dp[i][1] = 1;
         } else {
               if(dp[i - 1][0] + stair[i - 1] > dp[i - 2][0] + stair[i - 1]) {
                  dp[i][0] = dp[i - 1][0] + stair[i - 1];
                  dp[i][1] = dp[i - 1][1] + 1;
               } else {
                  dp[i][0] = dp[i - 2][0] + stair[i - 1];
                  dp[i][1] = 1;
               }
            }
         }
         cout << dp[i][0] << " ";
   }

   cout << dp[n][0] << '\n';


   return 0;
}