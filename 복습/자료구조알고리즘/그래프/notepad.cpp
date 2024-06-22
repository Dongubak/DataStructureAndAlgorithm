// 9 90 900 9000

// 1 2  3   4

#include <iostream>

using std::cin;
using std::cout;

int main(void) {
   long long n;
   cin >> n;
   long long sum = 0;
   long long prev = 9;

   for(int i = 1; i < 10; i++) {
      sum += 1 * n;
      if(n < prev) {
         break;
      }

      n -= prev;

      prev = prev * 10;
   }

   cout << sum;


   return 0;
}