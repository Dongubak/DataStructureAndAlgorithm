#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
   double r = 2.0;
   double a = 2.0;

   double x = a, y = pow(a, 2);

   for(int i = 0; i < 5; i++) {
      x = (y + r) / (2 * a);
      y = pow(x, 2);
      a = x;
   }

   cout << a;

   return 0;
}