#include <iostream>
using namespace std;

int main(void) {
   int M = 20;
   int a[6] = {21, 41, 61, 81, 101, 121};
   int r = 1;

   for(int i = 0; i < 6; i++) {
      r = (r * (a[i] % M)) % M;
   }

   cout << r << '\n';

   int M1 = 100;

   int b = 202112;
   b = b % 100;
   r = 1;
   for(int i = 0; i < 5; i++) {
      r = (r * b) % 100;
   }

   cout << r;

   return 0;
}