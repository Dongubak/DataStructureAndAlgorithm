#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct pos {
   int x;
   int y;

   pos(int X, int Y) : x(X), y(Y) {}
   double getDistance(pos p) {
      return sqrt(
         pow(x - p.x, 2) + pow(y - p.y, 2)
      );
   }
};

struct c {
   int x;
   int y;
   int r;

   c(int X = 0, int Y = 0, int R = 0) : 
   x(X), y(Y), r(R) {}

   pos retPos() {
      return pos(x, y);
   }
};

int sol(vector<c>& circles) {
   pos c1 = pos(
      circles[0].retPos()
   );
   int r1 = circles[0].r;

   pos c2 = pos(
      circles[1].retPos()
   );
   int r2 = circles[1].r;

   if(c1.getDistance(c2) < min(r1, r2)) {
      return 1;
   } else if(c1.getDistance(c2) == min(r1, r2)) {
      return 2;
   } else if(c1.getDistance(c2) < r1 + r2) {
      return 3;
   } else if(c1.getDistance(c2) == r1 + r2) {
      return 4;
   } else {
      return 5;
   }
}


int main(void) {
   int x, y, r;
   
   vector<c> circles(2);

   for(int i = 0; i < 2; i++) {
      cin >> x >> y >> r;
      circles[i] = c(x, y, r);
   }

   cout << sol(circles);

   return 0;
}