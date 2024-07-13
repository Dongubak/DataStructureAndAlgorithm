#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::pair;

int N, M;

vector<vector<int>> A;

#define WBUF_SIZE (1 << 20)

char rbuf[WBUF_SIZE];
int ridx, nidx;

inline char read() {
	if (ridx == nidx) {
		nidx = fread(rbuf, 1, 1 << 20, stdin);
		if (!nidx) return 0;
		ridx = 0;
	}
	return rbuf[ridx++];
}
inline int readInt() {
	int sum = 0;
	char now = read();
	bool flg = false;

	while (now <= 32) now = read();
	if (now == '-') flg = true, now = read();
	while (now >= 48) sum = sum * 10 + now - '0', now = read();

	return flg ? -sum : sum;
}

inline long long readLong() {
	long long sum = 0;
	char now = read();
	bool flg = false;

	while (now <= 32) now = read();
	if (now == '-') flg = true, now = read();
	while (now >= 48) sum = sum * 10 + now - '0', now = read();

	return flg ? -sum : sum;
}


int main(void) {
   N = readInt();
   M = readInt();
   // cin >> N >> M;
   
   A.resize(N, vector<int>(N));

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
			A[i][j] = readInt();
		}
   }
	
	int sr, sc, er, ec;


	for(int i = 0; i < M; i++) {
		sr = readInt() - 1;
		sc = readInt() - 1;
		er = readInt() - 1;
		ec = readInt() - 1;

		int sum = 0;
		for(int j = sr; j <= er; j++) {
			for(int k = sc; k <= ec; k++) {
				sum += A[j][k];
			}
		}

		cout << sum << '\n';
	}

   return 0;
}