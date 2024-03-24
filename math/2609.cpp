#include <iostream>
using namespace std;

int sol(int a, int b) {
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
   int a, b, c;

   cin >> a >> b;
   cout << (c = sol(a, b)) << '\n';
   cout << a * b / c;

   return 0;
}