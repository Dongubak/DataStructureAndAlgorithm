#include <bits/stdc++.h>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, tm;
   cin >> n;
   int x = 1, y;
   for(int i = 0; i < n; i++) {

      cin >> tm;
      y = tm - 1;
      cout << "Pairs for " << tm << ": ";
      while(x < y && x > 0 && y > 0 && x + y == tm) {
         if(x + 1 >= y - 1) {
            cout << x << " " << y;
         } else {
            cout << x << " " << y << ", ";
         }

         x++;
         y--;
      }

      cout << '\n';
      x = 1;
   }

   return 0;
}