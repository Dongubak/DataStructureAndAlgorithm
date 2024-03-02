#include <bits/stdc++.h>
using namespace std;

bool isInFirstCircle(int x, int y) {
   if((x - 3) * (x - 3) + (y - 7) * (y - 7) <= 4) {
      return true;
   }
   return false;
}

bool isInSecondCircle(int x, int y) {
   if((x - 3) * (x - 3) + (y - 3) * (y - 3) <= 9) {
      return true;
   }
   return false;
}

int main(void) {
   srand(unsigned(time(0)));
   // 임의의 좌표 x 의 범위는 0 - 6
   // 임의의 좌표 y 의 범위는 0 - 9

   int rPositionOfX, rPositionOfY;
   int c = 0;
   for(int i = 0; i < 1000000; i++) {
      rPositionOfX = rand() % 7, rPositionOfY = rand() % 10;
      if(isInFirstCircle(rPositionOfX, rPositionOfY) ||
         isInSecondCircle(rPositionOfX, rPositionOfY)
      ) {
         c++;
      }
   }

   cout << c / 1000000. * 54;

   return 0;
}