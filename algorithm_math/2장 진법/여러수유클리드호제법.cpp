#include <bits/stdc++.h>
using namespace std;

int e_gcd(int a, int b) {
   while(a && b) {
      if(a > b) {
         a = a % b;
      } else {
         b = b % a;
      }
   }

   return a ? a : b;
}

int main(void) {

   int n, t;
   cin >> n;

   vector<int> k(n);

   for(int i = 0; i < n; i++) {
      cin >> t;
      k[i] = t;
   }

   int prev = 0;

   for(int i = 0; i < n - 1; i++) {
      if(i == 0) {
         prev = e_gcd(k[i], k[i + 1]);
      } else {
         prev = e_gcd(prev, k[i + 1]);
      }
   }

   cout << prev;

   return 0;
}