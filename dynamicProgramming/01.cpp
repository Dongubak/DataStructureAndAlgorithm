#include <iostream>
#include <vector>
using namespace std;

int dp[1000000 + 1];

int main(void) {

   int N;
   cin >> N;

   dp[0] = 1;
   dp[1] = 1;
   for(int i = 2; i <= N; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
   }

   cout << dp[N];

   return 0;
}