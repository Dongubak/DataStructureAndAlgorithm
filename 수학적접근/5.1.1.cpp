#include <iostream>
using namespace std;

int abs(int x) {
   return x < 0 ? -x : x;
}

int main(void) {
   int n, x, y;

   cin >> n >> x >> y;
   
   if(abs(x) + abs(y) <= n) {
      if((abs(x) + abs(y)) % 2 == 0) { ///짝수
         cout << (n % 2 == 0 ? "Yes" : "No");
      } else {
         cout << (n % 2 != 0 ? "Yes" : "No");
      }
   } else {
      cout << "No";
   }
   


   return 0;
}