#include <iostream>

int main(void) {

   int a = 1071, b = 1029;

   // 2개의 자연수 a, b(a > b)에 대해서 a를 b로 나눈 나머지가 r일 때, a와 b의 최대공약수는 b와 r의 최대공약수와 같다.

   if(a < b) {
      int tmp = a;
      a = b;
      b = tmp;
   }

   if(a % b == 0) {
      std::cout << b;
   } else {
      a = a % b;
      int tmp = a;
      a = b;
      b = tmp;

      while(a % b != 0) {
         a = a % b;
         tmp = a;
         a = b;
         b = tmp;
      }

      std::cout << b;
   }

   return 0;
}