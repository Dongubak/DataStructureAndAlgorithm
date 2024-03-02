#include <iostream>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, r;
   cin >> n >> r;

   int res = 1;

   for(int i = n, j = 1; i >= n - r + 1; i--, j++) {
      res = res * i / j;
   }

   cout << res;

   return 0;
}