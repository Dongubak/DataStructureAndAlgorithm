#include <iostream>

int main(void) {
   using namespace std;

   /*
      최대공약수 : greatest common divisor
      gcd(a, b); or GCD(a, b);

      최소공배수 : least common multiple
      lcm(a, b); or LCM(a, b);

   */
   int c;
   int n, m;
   cin >> c;

   for(int i = 0; i < c; i++) {
      cin >> n >> m;
      int j = 1, k = 1;
      while(n != m) {
         if(n > m) {
            m /= k;
            m *= ++k;
         } else { /// n < m
            n /= j;
            n *= ++j;
         }
      }
      cout << m << '\n';
   }

   




   return 0;
}