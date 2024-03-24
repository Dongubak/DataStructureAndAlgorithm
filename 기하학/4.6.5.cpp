#include <iostream>
using namespace std;

long long pow_m(long long a, long long b, int MOD) {
   long long result = 1;
   while (b > 0) {
      if (b % 2 == 1)
         result = (result * a) % MOD;
      a = (a * a) % MOD;
      b = b >> 1;
   }
   return result;
}

int main(void) {
    int X, Y;
    cin >> X >> Y;

    int M = 1000000007;

    long long a = 1, b = 1; // a는 분자, b는 분모

    for (int i = 1; i < X + Y + 1; i++) {
        a = (a * i) % M;
    }

    for (int i = 1; i < X + 1; i++) {
        b = (b * i) % M;
    }

    for (int i = 1; i < Y + 1; i++) {
        b = (b * i) % M;
    }

    cout << (a * pow_m(b, M - 2, M)) % M;

    return 0;
}