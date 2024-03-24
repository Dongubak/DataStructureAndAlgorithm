#include <iostream>
#include <cmath>
using namespace std;

int n[100000 + 1];
int dp[100000 + 1];

int main(void) {
   int n;
   cin >> n;

   for(int i = 0; i < n; i++) {
      cin >> ::n[i];
   }

   dp[1] = ::n[0];

   for(int i = 2; i <= n; i++) {
      ::dp[i] = max(dp[i - 1] + ::n[i - 1], dp[i - 1]);
      cout << "i = " << i << " : " << dp[i] << '\n';
   }

   

   return 0;
}