#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
   for(int i = 2; i * i <= n; i++) {
      if(n % i == 0) {
         return false;
      }
   }
   return true;
}

int main(void) {
   int n, t;
   cin >> n;

   for(int i = 0; i < n; i++) {
      cin >> t;

      for(int j = t / 2; j > 1; j--) {
         if(isPrime(j) && isPrime(t - j)) {
            cout << j << " " << t - j << '\n';
            break;
         }
      }
   }

   return 0;
}