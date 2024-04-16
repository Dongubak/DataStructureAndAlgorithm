#include <iostream>
using namespace std;

int bcountry[100000 + 1];

int main(void) {
   int n, q;
   cin >> n >> q;

   int l, r, x;

   for(int i = 0; i < q; i++) {
      cin >> l >> r >> x;
      bcountry[l] += x;
      if(r + 1 <= n) {
         bcountry[r + 1] -= x; 
      }
   }

   for(int i = 2; i < n + 1; i++) {
      bcountry[i] = bcountry[i] + bcountry[i - 1];
   }

   for(int i = 1; i < n; i++) {
      if(bcountry[i] < bcountry[i + 1]) {
         cout << '<';
      } else if(bcountry[i] > bcountry[i + 1]) {
         cout << '>';
      } else {
         cout << '=';
      }
   }

   return 0;
}