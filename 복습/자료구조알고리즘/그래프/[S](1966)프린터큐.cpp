#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::find;

int main(void) {
   // 1 0
   // 5
   int N, T;
   cin >> N >> T;
   
   int c, f;
   vector<int> a(N);
   for(int i = 0; i < N; i++) {
      cin >> a[i];
   }

   c = 0, f = a[T];

   while(c != N) {
      int mj = -1;
      int max = 0;

      for(int i = 0; i < N; i++) {
         if(a[i] > max) {
            max = a[i];
            mj = i;
         }
      }

      cout << "mj : " << mj << '\n';

      int pp = a[mj];
      c += 1;
      if(pp == f) {
         cout << c << '\n';
         return 0;
      }
      a.erase(a.begin() + mj);

      for(auto c: a) {
         cout << c << " ";
      }
      cout << '\n';
   }

   return 0;
}