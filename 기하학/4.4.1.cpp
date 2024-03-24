#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
   int N;

   cin >> N;
   vector<int> p(N + 1, 1);

   for(int i = 2; pow(i, 2) < N; i++) {
      if(p[i] == 1) {
         for(int j = 2 * i; j < N; j = j + i) {
            p[j] = 0;
         }
      }
   }

   for(int i = 2; i < N + 1; i++) {
      if(p[i] == 1) {
         cout << i << '\n';
      }
   }

   return 0;
}