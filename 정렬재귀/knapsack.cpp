#include <bits/stdc++.h>
using namespace std;


int main(void) {
   int N, M;

   cin >> N >> M;

   vector<int> w(N); ///1번째 물건의 무게는 index 0에 존재
   vector<int> v(N); ///1번째 물건의 가치는 index 0에 존재

   vector<vector<int>> dp(M + 1, vector<int>(N + 1)); ///열의 값은 무게의 합이며 M이 최대값이다. M인덱싱 가능
   
   for(int i = 0; i < M + 1; i++) {
      for(int j = 0; j < N + 1; j++) {
         dp[i][j] = -10e5;
      }
   }

   int tmpW, tmpV;

   for(int i = 0; i < N; i++) {
      cin >> tmpW >> tmpV;
      w[i] = tmpW, v[i] = tmpV;
   }

   dp[0][0] = 0;

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < M + 1; j++) { ///j는 M까지 인덱싱함
         // 1. i번째 물건을 뽑지 못함 (j - w[i] 값이 음수임)
         // 2. i번째 물건을 뽑을 수 있음 (j - w[i] 값이 양수임)

         if(j - w[i] < 0) { ///i번째 물건 선택 불가능
            dp[i + 1][j] = dp[i][j];
         } else { ///i번째 물건 선택 가능
            dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
         }
      } 
   }

   int tmpM = dp[N][0];

   for(int i = 1; i < M + 1; i++) {
      if(dp[N][i] > tmpM) {
         tmpM = dp[N][i];
      }
   }

   cout << tmpM;

   return 0;
}