#include <bits/stdc++.h>
using namespace std;

void func(int n, int b) {
   string out = "";
   while(n >= 1) {
      int r = n % b;
      if(r < 10) {
         out = char(r + '0') + out;
      } else {
         out = char(r - 10 + 'A') + out;
      }

      n /= b;
   }

   cout << out << " ";
}

int main(void) {

   int n, k, index;
   cin >> n;

   int b[3] = {8, 10, 16};

   for(int i = 0; i < n; i++) {
      cin >> index >> k;
      cout << index << " ";
      for(int i = 0; i < 3; i++) {
         func(k, b[i]);
      }

      cout << '\n';
   }

   return 0;
}