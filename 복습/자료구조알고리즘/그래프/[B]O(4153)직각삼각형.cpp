#include <iostream>

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
   int a, b, c;
   while(1) {
      a =readInt();
      b =readInt();
      c =readInt();

      if(a == 0 && b == 0 && c == 0) {
         break;
      }
      bool flag = false;

      a = a * a; b = b * b; c = c * c;

      if(a == b + c) {
         cout << "right" << '\n';
         continue;
      }

      if(b == a + c) {
         cout << "right" << '\n';
         continue;
      }

      if(c == b + a) {
         cout << "right" << '\n';
         continue;
      }

      cout << "wrong" << '\n';
   }
}