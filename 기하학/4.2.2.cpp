#include <iostream>
using namespace std;

int main(void) {
   int T, N, l, r;
   cin >> T >> N;

   vector<int> t(T, 0);

   for(int i = 0; i < N; i++) {
      cin >> l >> r;

      for(int i = l; i < r; i++) {
         t[i] += 1;
      }
   }

   for(int i = 0; i < T; i++) {
      cout << t[i] << '\n';
   }

   return 0;
}