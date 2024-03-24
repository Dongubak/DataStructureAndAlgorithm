#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
   double a = 2.0;
   double x = 2.0, y = pow(x, 3);
   
   for(int i = 0; i < 5; i++) {
      x = (2. / 3.) * a + 2. / (3. * pow(a, 2));
      y = pow(x, 3);
      a = x;
   }

   cout << a;

   return 0;
}