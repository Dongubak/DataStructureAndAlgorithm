#include <bits/stdc++.h>
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c) {
   if(a <= 0 || b <= 0 || c <= 0) {
      return 1;
   } else if(a > 20 || b > 20 || c > 20) { ///20보다 크면 20으로 조정함
      if(dp[20][20][20] == -1) {
         dp[20][20][20] = w(20, 20, 20);
      }
      return dp[20][20][20];
   } else if(dp[a][b][c] != -1) {

     return dp[a][b][c]; 

   } else if(a < b && b < c) { ///a < b < c

      dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
      return dp[a][b][c];      
   } else { ///나머지 경우
      dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
      return dp[a][b][c];
   }
}

int main(void) {
   // ios_base::sync_with_stdio(false);
   // cin.tie(nullptr);

   int a, b, c;
   cin >> a >> b >> c;

   memset(dp, -1, sizeof(dp));

   while(!(a == -1 && b == -1 && c == -1)) {
      cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
      cin >> a >> b >> c;
   }

   return 0;
}