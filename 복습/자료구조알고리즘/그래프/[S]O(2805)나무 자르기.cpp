#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main(void) {
   long N, M, t;
   cin >> N >> M;

   vector<long> heights(N);

   long tmp_max = -1;

   for(int i = 0; i < N; i++) {
      cin >> t;
      heights[i] = t;
      tmp_max = max(t, tmp_max);
   }
   long optL = 0;
   long left = 0, right = tmp_max;

   while(left <= right) {
      long m = (left + right) / 2;
      long sum = 0;

      for(auto ptr = heights.begin(); ptr != heights.end(); ptr++) {
         if(*ptr - m > 0) {
            sum += (*ptr - m);
         }
      }

      if(sum >= M) {
         left = m + 1;
         optL = m;
      } else {
         right = m - 1;
      }
   }

   cout << optL;

   return 0;
}