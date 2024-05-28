#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
   vector<int> dp(1000000 + 1, numeric_limits<int>::max());

   dp[1] = 0;

   int n;
   cin >> n;

   for(int i = 1; i <= n; i++) {
      if(i + 1 <= n) {
         dp[i + 1] = min(dp[i + 1], dp[i] + 1);
      }

      if(i * 2 <= n) {
         dp[2 * i] = min(dp[2 * i], dp[i] + 1);
      }

      if(i * 3 <= n) {
         dp[3 * i] = min(dp[3 * i], dp[i] + 1);
      }
      
      // cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << '\n';
   }

   cout << dp[n];
   
   

   return 0;
}