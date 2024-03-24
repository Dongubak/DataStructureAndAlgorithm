#include <iostream>
using namespace std;

int main(void) {
   int i = 1;
   double r = 0;

   while(r <= 20) {
      r += 1.0 / (i + 1);
      i += 1;
   }

   cout << i - 1;

   return 0;
}
