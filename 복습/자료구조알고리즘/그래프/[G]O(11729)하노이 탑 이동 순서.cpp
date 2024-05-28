#include <iostream>
using namespace std;

int co[21];

void rec(int m, int c, int d, int b) {
   if(m == 1) {
      cout << c << " " << d << '\n';
      return;
   }
   rec(m - 1, c, b, d);
   cout << c << " " << d << '\n';
   rec(m - 1, b, d, c);
}

void sol(int n) {
   rec(n, 1, 3, 2);
}

int main(void) {

   int n;
   cin >> n;

   co[1] = 1;
   for(int i = 1; i <= n; i++) {
      co[i] = 2 * co[i - 1] + 1;
   }
   cout << co[n] << '\n';
   sol(n);

   return 0;
}
