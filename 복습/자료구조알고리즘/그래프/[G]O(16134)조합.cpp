#include <iostream>
using namespace std;

const int M = 1000000007;

long long pow_m(long long base, int exp) {
   long long res = 1;
   long long i = base;

   while(exp > 0) {
      if(exp % 2 != 0) {
         res = ((res % M) * (i % M)) % M;
      }
      i = (i * i) % M;

      exp = exp >> 1;
   }

   return res;
}

long long mod_inv(long long B) {
   return pow_m(B, M - 2);
}

void sol(long long t, long long d) {
   long long inv = mod_inv(d);

   long long ans = (t * inv) % M;

   cout << ans;
}


int main(void) {
   int n, r;

   cin >> n >> r;

   long long t = 1, d = 1;

   for(int i = n; i > n - r; --i) {
      t = ((t % M) * (i % M)) % M;
   }

   for(int i = 1; i <= r; ++i) {
      d = ((d % M) * (i % M)) % M;
   }


   sol(t, d);
   

   return 0;
}