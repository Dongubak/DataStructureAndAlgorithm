#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
   int res = 0;

   for(int i = 1; i < min(a, b) + 1; i++) {
      if(!(a % i) && !(b % i)) {
         res = i;
      }
   }

   return res;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int a, b;
   cin >> a >> b;

   cout << gcd(a, b);

   return 0;
}