#include <iostream>

int main(void) {
   using namespace std;
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   long a, b; ///첫번쨰 수의 분자 분모
   long c, d; ///두번째 수의 분자 분모

   cin >> a >> b;
   cin >> c >> d;

   long r1 = a * d + c * b;
   long r2 = b * d;
   bool s = false;

   if(r1 < r2) {
      int tmp = r1;
      r1 = r2;
      r2 = tmp;
      s = true;
   }

   if(r1 % r2 == 0) {
      if(s) {
         cout << r2 / r2 <<  " " << r1 / r2;
      } {
         cout << r1 / r2 <<  " " << r2 / r2;   
      }
   } else {
      a = a % b;
      long tmp = a;
      a = b;
      b = tmp;
      while(a % b != 0) {
         a = a % b;
         tmp = a;
         a = b;
         b = tmp;
      }
      if(s) {
         cout << r2 / b <<  " " << r1 / b;   
      } else {
         cout << r1 / b <<  " " << r2 / b;
      }
      
   }

   return 0;
}