#include <iostream>
#include <cmath>
using namespace std;

int gcd(int n1, int n2) {
   while(n1 && n2) {
      if(n1 > n2) {
         n1 = n1 % n2;
      } else {
         n2 = n2 % n1;
      }
   }

   return n1 ? n1 : n2;
}

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int t1, b1;
   int t2, b2;

   int t3, b3;

   cin >> t1 >> b1;
   cin >> t2 >> b2;

   t3 = t2 * b1 + t1 * b2;
   b3 = b1 * b2;
   
   int g = gcd(t3, b3);

   cout << t3 / g << " " << b3 / g;

   return 0;
}