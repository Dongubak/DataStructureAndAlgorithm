#include <iostream>
#include <cmath>

using namespace std;

struct p {
   double x;
   double y;
   p (int d, int t, char a, int m = 0) {
      const double M = a == 'H' ? 30 : 6;
      x = d * cos((90 - M * t + (90 - 6 * m) * 1 / 12) * M_PI / 180);
      y = d * sin((90 - M * t + (90 - 6 * m) * 1 / 12) * M_PI / 180);
   }

   double getDistance(p p1) {
      return sqrt(pow(x - p1.x, 2) + pow(y - p1.y, 2));
   }
};

int main(void) {
   int A, B, H, M;

   cin >> A >> B >> H >> M;

   p p1(A, H, 'H', M);
   p p2(B, M, 'M');

   cout << p1.x << " " << p1.y << '\n';
   cout << p2.x << " " << p2.y << '\n';

   cout << p1.getDistance(p2);

   return 0;
}