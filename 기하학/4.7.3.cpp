#include <iostream>
using namespace std;

const int MOD = 1000000007;

struct MAT {
    long long a[3][3];

    MAT(long long a11, long long a12, long long a13,
        long long a21, long long a22, long long a23,
        long long a31, long long a32, long long a33) {
        a[0][0] = a11; a[0][1] = a12; a[0][2] = a13;
        a[1][0] = a21; a[1][1] = a22; a[1][2] = a23;
        a[2][0] = a31; a[2][1] = a32; a[2][2] = a33;
    }

    MAT operator*(const MAT &m) const {
        MAT result(0, 0, 0, 0, 0, 0, 0, 0, 0);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    result.a[i][j] += (a[i][k] * m.a[k][j]) % MOD;
                    result.a[i][j] %= MOD;
                }
            }
        }
        return result;
    }
};

int main(void) {
   MAT st = MAT(1, 1, 1, 1, 0, 0, 0, 1, 0);

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

   cout << ans.a[0][0];

   return 0;
}