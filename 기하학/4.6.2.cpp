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
    int X, Y;
    cin >> X >> Y;

    int M = (2 * X - Y) / 3;
    int N = (2 * Y - X) / 3;

    long long t = 1, d = 1;
    for (int i = 1; i < M + N + 1; i++) {
        t = (t * i) % MOD;
    }

    for (int i = 1; i <= M; i++) {
        d = (d * i) % MOD;
    }

    for (int i = 1; i <= N; i++) {
        d = (d * i) % MOD;
    }
    
    if (M + 2 * N == X) {
        cout << ((long long)t * pow_m(d, MOD - 2)) % MOD;
    } else {
        cout << 0;
    }

    return 0;
}
