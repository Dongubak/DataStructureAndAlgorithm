#include <bits/stdc++.h>
using namespace std;

int main(void) {

   int N, S;

   N = 35;
   S = 10000;

   vector<int> c(N);

   for(int i = 0; i < N; i++) {
      c[i] = i + 1;
   }

   for(int i = 0; i < (1 << N); i++) {
      int pSum = 0;
      for(int j = 0; j < N; j++) {
         if(i & (1 << j) != 0) {
            pSum += c[j];
         }
      }

      if(pSum == S) {
         cout << "Yes";
         break;
      }
   }

   return 0;
}