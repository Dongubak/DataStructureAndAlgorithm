#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::sort;

int main() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(NULL);

   int c;
   cin >> c;
   int n, L;
   for(int i = 0; i < c; i++) {
      cin >> n >> L;
      vector<int> A(n);
      vector<int> B(n);
      
      for(int j = 0; j < n; j++) {
         cin >> A[j];
      } 
      sort(A.begin(), A.end());
      for(int j = 0; j < n; j++) {
         cin >> B[j];
      }

      bool ff = false;
      int max = 0;

      int count = 1;
      for(int o = 2; o <= n; o++) {
         count *= o;
      }

      for(int j = 0; j < count; j++) {
         bool f = true;
         int tmax = 0;
         for(int k = 0; k < n; k++) {
            int temp = std::abs(A[k] - B[k]);
            if(temp > L) {
               f = false;
            }

            tmax = std::max(tmax, temp);
         }

         if(f) {
            ff = true;
            max = std::max(max, tmax);
         }

         std::next_permutation(A.begin(), A.end());
      }
      if(!ff) {
         cout << "Case #" << i + 1 << endl << -1 << endl;
      } else {
         cout << "Case #" << i + 1 << endl << max << endl;
      }
   }

    return 0;
}
