#include <iostream>
using namespace std;

long long pow_m(long long a, long long b, int m) {
   long long p = a;
   long long res = 1;

   while(b > 0) {
      if(b % 2 == 1) {
         res = (res * p) % m;
      }
      p = (p * p) % m;

      b = b >> 1;
   }

   return res;
}

long long getInv(long long b, int m) {
   return pow_m(b, m - 2, m);
}


int main(void) {
   int n, k, m;

   cin >> n >> k >> m;

   long long b = 1;
   long long t = 1;

   // nCk = n! / k!(n-k)!
   // n*n-1*...*n-k+1
   // 1 * 2 * ... * k;

   // 5!





   // cout << "b : " << b << '\n';
   // cout << "t : " << t << '\n';

   // long long inv = getInv(b, m);
   // cout << (inv * t) % m;

   return 0;
}