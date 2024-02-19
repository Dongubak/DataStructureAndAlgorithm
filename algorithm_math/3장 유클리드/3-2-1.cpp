#include <bits/stdc++.h>
using namespace std;

void gcd(int a, int b) {
   int res = 0;
   while(a && b) {
      if(a > b) {
         a = a % b;
      } else {
         b = b % a;
      }

      cout << a << " " << b << '\n';
   }
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int a, b;
   cin >> a >> b;

   gcd(a, b);


   return 0;
}