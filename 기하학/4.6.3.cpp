#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long pow_m(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

int main(void) {
   int N;

   cin >> N;

   long long ans = ((pow_m(4, N + 1) - 1) * pow_m(3, MOD - 2)) % MOD;

   cout << ans;


   return 0;
}