#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
   double l = 1.0, r = 2.0;
   double m;
   for(int i = 0; i < 50; i++) {
      m = (l + r) / 2;
      if(pow(m, 2) < 2) {
         l = m;
      } else {
         r = m;
      }

      cout << i + 1 << " : " << m << '\n';
   }

   cout << m;


   return 0;
}