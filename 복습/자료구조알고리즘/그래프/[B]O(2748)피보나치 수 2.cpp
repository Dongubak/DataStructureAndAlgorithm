#include <iostream>

using namespace std;

long dp[10000];

long fib(int n) {
   if(n <= 2) {
      return dp[n];
   }

   return dp[n] = (dp[n - 1] ? dp[n - 1] : fib(n - 1)) + (dp[n - 2] ? dp[n - 2] : fib(n - 2));
}

int main(void) {
   int n;
   cin >> n;

   dp[1] = 0;
   dp[2] = 1;

   cout << fib(n + 1);

   return 0;
}