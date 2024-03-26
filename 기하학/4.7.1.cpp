#include <iostream>
using namespace std;

const int MOD = 1000000000;

struct MAT {
   long long a[2][2];

   MAT(long long a11, long long a12, long long a21, long long a22) {
      a[0][0] = a11;
      a[0][1] = a12;
      a[1][0] = a21;
      a[1][1] = a22;
   }

   MAT operator*(MAT m) {
      long long c[2][2] = {{0, 0}, {0, 0}};

      for(int i = 0; i < 2; i++) {
         for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
               c[i][j] += (a[i][k] * m.a[k][j]) % MOD;
               c[i][j] %= MOD;
            }
         }
      }
      return MAT(c[0][0], c[0][1], c[1][0], c[1][1]);
   }
};


int main(void) {
   MAT st = MAT(1, 1, 1, 0);

   long long N;
   cin >> N;
   N = N - 2;

   MAT p = st;
   MAT ans = st;
   
   while(N > 0) {
      if(N % 2 != 0) {
         ans = ans * p;
      }
      p = p * p;

      N = N >> 1;
   }

   cout << (ans.a[1][0] + ans.a[1][1]) % MOD << '\n';


   return 0;
}