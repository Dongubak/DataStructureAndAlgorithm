#include <bits/stdc++.h>
using namespace std;

int main(void) {

   int n;
   cin >> n;

   
   string out = "";

   while(n >= 1) {
      out = char(48 + n % 2) + out;
      n /= 2;
   }

   cout << out;
   

   return 0;
}