#include <iostream>
#include <cmath>
using namespace std;

struct pos {
   double x, y;

   pos(double X = 0, double Y = 0) : x(X), y(X) {};

   pos operator+(pos p) {
      return pos(x + p.x, y + p.y);
   }

   pos operator-(pos p) {
      return pos(x - p.x, y - p.y);
   };

   double operator*(pos p) {
      return x * p.x + y + p.y;
   };

   double operator/(pos p) {
      return x * p.y - y * p.x;
   };

   double abs() {
      return sqrt(pow(x, 2) + pow(y, 2));
   }

   pos inv() {
      return pos(-x, -y);
   }
};

int main(void) {
   pos A, B, C;

   cin >> A.x >> A.y;
   cin >> B.x >> B.y;
   cin >> C.x >> C.y;

   pos AB, BC, CA;
   AB = B - A;
   BC = C - B;
   CA = A - C;

   if(AB.inv() * BC < 0) {
      ///BA * BC 가 음수면 AB
      cout << AB.abs();
   } else if(BC.inv() * CA < 0) {
      ///CB * CA 가 음수
      cout << CA.abs();
   } else {
      ///d = (BA / BC) / BC
      cout << (AB.inv() / BC) / BC.abs();
   }
   

   return 0;
}