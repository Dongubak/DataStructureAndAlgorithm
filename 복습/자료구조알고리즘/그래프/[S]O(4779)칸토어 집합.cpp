#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

char a[531441 + 1];

void rec(int p, int q) {
   int m = p + (q - p + 1) / 3;
   int n = p + (q - p + 1) * 2 / 3;
   if(p >= q - 1) {
      return;
   }

   for(int i = m; i < n; i++) {
      a[i] = 1;
   }

   rec(p, m);
   rec(n, q);
} 

void sol(int n) {
   rec(1, n + 1);
}

int main(void) {
   int t;

   while(cin >> t) {
      sol(pow(3, t));
      for(int i = 1; i <= pow(3, t); i++) {
         if(a[i] == 0) {
            cout << '-';
         } else {
            cout << ' ';
         }
      }
      cout << '\n';
      memset(a, 0, sizeof(a));
   }
   

   return 0;
}