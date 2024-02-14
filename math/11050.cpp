#include <bits/stdc++.h>
using namespace std;

int getFac(int n) {
   int res = 1;

   for(int i = 2; i <= n; i++) {
      res *= i;
   }

   return res;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, k;
   cin >> n >> k;

   // n! / (n-k)!k!

   cout << getFac(n) / (getFac(n - k) * getFac(k));

   return 0;
}