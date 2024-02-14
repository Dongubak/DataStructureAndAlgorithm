#include <bits/stdc++.h>
using namespace std;

int dp[21][2000001];

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, t, k;
   cin >> n >> t;
   vector<int> a(n);
   for(int i = 0; i < n; i++) {
      cin >> k;
      a[i] = k;
   }
   sort(a.begin(), a.end());

   for(int i = 0; i < n + 1; i++) {
      dp[i][0] = 1;
   }

   int sum = accumulate(a.begin(), a.end(), 0);
   
   for(int i = 1; i < n + 1; i++) {
      for(int j = 1; j < sum + 1; j++) {
         if(j < a[i - 1]) {
            dp[i][j] = dp[i - 1][j];
         } else {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
         }
      } 
   }

   


   cout << dp[n][5];
   

   return 0;
}