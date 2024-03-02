#include <bits/stdc++.h>
using namespace std;

int dp[10000 + 1];

void sol(vector<int>& h, int n) {
   dp[1] = 0;

   for(int i = 2; i < n + 1; i++) {
      int s = dp[i - 1] + abs(h[i] - h[i - 1]);
      int d = dp[i - 2] + abs(h[i] - h[i - 2]);

      if(i != 2) {
         dp[i] = min(s, d);
      } else {
         dp[i] = s;
      }
   }

   cout << dp[n];
}

int main(void) {
   int n;
   cin >> n;

   vector<int> h(n + 1);

   for(int i = 1; i < n + 1; i++) {
      cin >> h[i];
   }

   sol(h, n);

   return 0;
}