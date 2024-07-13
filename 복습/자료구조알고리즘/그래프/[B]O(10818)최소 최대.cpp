#include <iostream>

using std::cin;
using std::cout;

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


int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int N = readInt();

   int tmp, tM = -1000000 - 1, tm = 1000000 + 1;

   for (int i = 0; i < N; i++) {
      tmp = readInt();
      tM = tmp > tM ? tmp : tM;
      tm = tmp < tm ? tmp : tm;
   }

  cout << tm << " " << tM;

  return 0;
}