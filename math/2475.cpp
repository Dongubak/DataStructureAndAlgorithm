#include <bits/stdc++.h>
using namespace std;

int pow(int n) {
   return n * n;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   vector<int> n(5);
   int t;

   for(int i = 0; i < 5; i++) {
      cin >> t;
      n[i] = t;
   }

   int res = 0;

   for(int i = 0; i < 5; i++) {
      res += pow(n[i]);
   }

   cout << res % 10;

   return 0;
}