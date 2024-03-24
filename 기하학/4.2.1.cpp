#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(void) {
   int N, n, d;
   int pd = 1;


   cin >> N;


   vector<int> s(N);

   for(int i = 0; i < N - 1; i++) {
      cin >> s[i];
   }

   // s[i] => i에서 i + 1로가는 거리
   int r = 0;


   cin >> n >> pd;
   
   for(int j = 0; j < n; j++) {
      cin >> d;

      if(pd < d) {
         for(int k = pd; k < d; k++) {
            r += s[k - 1]; // Corrected indexing
         }
      } else {
         for(int k = d; k < pd; k++) {
            r += s[k - 1]; // Corrected indexing
         }
      }

      pd = d;
   }

   cout << r;

   return 0;
}
