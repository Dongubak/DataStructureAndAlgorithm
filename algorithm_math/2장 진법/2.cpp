#include <bits/stdc++.h>
using namespace std;

int main(void) {

   int n;
   cin >> n;

   string out = "";

   while(n >= 1) {
      if(n % 2 == 0) {
         out = '0' + out;
      } else {
         out = '1' + out;
      }
      n /= 2;
   }

   cout << out;

   return 0;
}