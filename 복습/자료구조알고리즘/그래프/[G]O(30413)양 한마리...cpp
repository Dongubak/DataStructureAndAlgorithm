#include <iostream>
using namespace std;

const long long M = 1000000007;

long long pow_m(int a, long long b) {
   long long ans = 1;
   long long i = a;

   while(b > 0) {
      if(b % 2 != 0) {
         ans = ((ans % M) * (i % M)) % M;
      }
      i = (i * i) % M;

      b = b >> 1;
   }

   return ans;
}

long long get_inv(int a) {
   return pow_m(a, M - 2);
}

int main(void) {
   // a(rN - 1) / r- 1
   int a;
   long long b;
   cin >> a >> b;
   // long long c = 1000000000000;
   // cout << c << '\n';
   if(a == 1) {
      cout << (a * b) % M;
   } else if (b == 1) {
      cout << 1;
   } else {
      long long ans = ((get_inv(a - 1) % M) * ((pow_m(a, b) - 1) % M)) % M;
      cout << ans;
   }
   

   return 0;
}