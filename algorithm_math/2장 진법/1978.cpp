#include <bits/stdc++.h>
using namespace std;

int main(void) {

   int n, m = 0, t;
   cin >> n;
   
   vector<int> k(n);

   for(int i = 0; i < n; i++) {
      cin >> t;
      k[i] = t;
   }

   for(int i = 0; i < n; i++) {
      ///k[i]는 검사할 값
      if(k[i] == 1) {
         continue;
      }
      bool isPrime = true;
   
      for(int j = 2; j < int(pow(k[i], 0.5) + 1); j++) {
         if(k[i] % j == 0) {
            isPrime = false;
            break;
         }
      }

      if(isPrime) {
         m += 1;
         
      }
   }

   cout << m;

   return 0;
}