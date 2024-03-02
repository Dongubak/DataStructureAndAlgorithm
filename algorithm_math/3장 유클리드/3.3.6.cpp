#include <bits/stdc++.h>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n;
   cin >> n;

   vector<int> c(n);

   for(int i = 0; i < n; i++) {
      cin >> c[i];
   }

   int count = 0;

   for(int i = 0; i < n - 1; i++) {
      for(int j = i + 1; j < n; j++) {
         if(c[i] + c[j] == 100000) {
            count += 1;
         }
      }
   }

   cout << count;

   return 0;
}