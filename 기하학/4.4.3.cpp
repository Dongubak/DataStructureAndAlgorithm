#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
   int N;

   cin >> N;
   vector<int> p(N + 1, 1);

   for(int i = 2; i < N + 1; i++) {
      p[i] += 1;
      for(int j = 2 * i; j < N + 1; j = j + i) {
         p[j] += 1;
      }
   }

   long long r = 0;

   for(int i = 1; i < N + 1; i++) {
      r += i * p[i];
   }

   cout << r;

   return 0;
}