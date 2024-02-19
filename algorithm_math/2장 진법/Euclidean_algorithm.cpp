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

   int a, b;
   cin >> a >> b;

   cout << e_gcd(a, b);

   return 0;
}