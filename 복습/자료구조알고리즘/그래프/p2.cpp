#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::sort;



int main(void) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(NULL);

   int c, N;
   cin >> c;
   
   for(int i = 0; i < c; i++) {
      cin >> N;
      vector<int> n(N);
      for(int j = 0; j < N; j++) {
         cin >> n[j];
      }
      sort(n.begin(), n.end());
      long long sum = 0;
      int l = 0, r = N - 1;
      for(int k = 0; k < N / 4; k++) {
         sum += n[r] - n[l];
         ++l, --r;
      }

      sum *= 2;

      cout << "Case #" << i + 1 << endl << sum << endl;
   }

   return 0;
}