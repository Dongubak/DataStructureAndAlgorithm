#include <iostream>
using namespace std;

int fb[100 + 1];
int dp[100 + 1];

int main(void) {
   int n;
   cin >> n;
   fb[0] = 0;
   fb[1] = 1;
   fb[2] = 2;

   dp[1] = 9;
   dp[2] = 17;

   for(int i = 3; i <= n; i++) {
      fb[i] = fb[i - 1] + fb[i - 2];

      dp[i] = 2 * dp[i - 1] - fb[i - 1];
   }

   cout << fb[3];

   cout << dp[n];

   return 0;
}