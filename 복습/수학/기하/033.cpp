#include <iostream>
#include <cmath>
using namespace std;

struct pos {
   int x;
   int y;

   pos(int X = 0, int Y = 0) : x(X), y(Y) {}
   int operator*(pos B) {
      return x * B.x + y * B.y;
   }

   int cross(pos B) {
      return x * B.y - y * B.x;
   }

   double getLength() {
      return sqrt(pow(x, 2) + pow(y, 2));
   }
};

pos getVector(pos S, pos E) {
   return pos(E.x - S.x, E.y - S.y);
}

int main(void) {
   pos A, B, C;
   cin >> A.x >> A.y;
   cin >> B.x >> B.y;
   cin >> C.x >> C.y;

   if(getVector(B, A) * getVector(B, C) < 0) {
      cout << getVector(B, A).getLength();
   } else if(getVector(B, C) * getVector(C, A) < 0) {
      cout << getVector(C, A).getLength();
   } else {
      cout << getVector(B, A).cross(getVector(B, C)) / getVector(B, C).getLength();
   }

   return 0;
}