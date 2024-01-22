#include <iostream>

int main(void) {
   using namespace std;

   long long int a, b;
   cin >> a >> b;
   int i = 1, j = 1;
   while(a != b) {
      if(a > b) {
         b /= i;
         b *= ++i;
      } else {
         a /= j;
         a *= ++j;
      }
   }

   cout << a;


   return 0;
}