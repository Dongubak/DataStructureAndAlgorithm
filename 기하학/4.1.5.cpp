#include <iostream>
#include <vector>
using namespace std;

struct c {
   double a;
   double b;

   c(int A, int B) : a(A), b(B) {}
};

struct pos {
   int x;
   int y;

   pos(int X = 0, int Y = 0) : x(X), y(Y) {}

   c getC(pos p1) {
      double a = (p1.y - y) / (p1.x - x);
      return c(a, y - a * x);
   }
};

bool sol(vector<pos>& ps) {
   c c1 = ps[0].getC(ps[1]);
   c c2 = ps[2].getC(ps[3]);

   if(c1.a - c2.a == 0) {
      return 0;
   } else {
      double x = (c2.b - c1.b) / (c1.a - c2.a);

      if(ps[0].x <= x && x <= ps[1].x &&
         ps[2].x <= x && x <= ps[3].x
      ) {
         return 1;
      } else {
         return 0;
      }
   }
}

int main(void) {

   vector<pos> ps(4);

   for(int i = 0; i < 4; i++) {
      cin >> ps[i].x;
      cin >> ps[i].y;
   }

   cout << (sol(ps) ? "Yes" : "No");

   return 0;
}