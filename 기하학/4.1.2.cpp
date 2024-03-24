#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct pos {
   int x;
   int y;

   pos(int X = 0, int Y = 0) : x(X), y(Y) {};

   double getDistance(pos p) {
      return sqrt(pow(x - p.x, 2) + 
      pow(y - p.y, 2));
   }
};

int main(void) {
   int n;
   int x, y;
   cin >> n;
   vector<pos> p(n);
   double d = 10e5;
   for(int i = 0; i < n; i++) {
      cin >> x >> y;
      p[i] = pos(x, y);
   }

   for(int i = 0; i < n - 1; i++) {
      for(int j = i + 1; j < n; j++) {
         if(p[i].getDistance(p[j]) < d) {
            d = p[i].getDistance(p[j]);
         }
      }
   }

   cout << d;

   return 0;
}