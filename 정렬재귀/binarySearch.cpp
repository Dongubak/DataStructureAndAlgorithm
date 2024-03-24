#include <bits/stdc++.h>
using namespace std;

int main(void) {
   int n;
   cin >> n;

   int B, C;
   
   vector<int> s(n);

   for(int i = 0; i < n; i++) {
      cin >> s[i];
   }

   cin >> B >> C;

   int res = 0;
   for(int i = 0; i < n; i++) {
      // 1. (총)포함
      int n1 = 1;
      int rest1 = s[i] - B;
      while(rest1 > 0) {
         rest1 -= C;
         n1++;
      }

      int n2 = 0;
      int rest2 = s[i];
      // 2. (총) 미포함
      while(rest2 > 0) {
         rest2 -= C;
         n2++;
      }

      if(n1 >= 0 && n2 >= 0) {
         res += min(n1, n2);
      } else {
         res += n1 < 0 ? n2 : n1;
      }
   }

   cout << res;


   

   return 0;
}