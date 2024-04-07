#include <iostream>
using namespace std;

int dp[1000000 + 1][1000 + 1];

int main(void) {
   int N, M, t;
   cin >> N >> M;

   vector<int> a(N);
   for(int i = 0; i < N; i++) {
      cin >> t;
      a[i] = t % M;
   }

   for(int i = 0; i < N; i++) {
      cout << a[i] << " ";
   }

   for(int i = 1; i < N; i++) {
      for(int j = 1; j < 1000 + 1; j++) {
         
      }
   }

   return 0;
}