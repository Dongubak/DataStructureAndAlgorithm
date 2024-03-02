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

   for(int i = 0; i < n - 4; i++) {
      for(int j = i + 1; j < n - 3; j++) {
         for(int k = j + 1; k < n - 2; k++) {
            for(int l = k + 1; l < n - 1; l++) {
               for(int m = l + 1; m < n; m++) {
                  if(c[i] + c[j] + c[k] + c[l] + c[m] == 1000) {
                     count += 1;
                  }
               }
            }
         }
      }
   }

   cout << count;

   return 0;
}