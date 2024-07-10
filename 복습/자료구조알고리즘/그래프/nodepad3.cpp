#include <cstdio>
#include <string>

#define WBUF_SIZE (1 << 20)

using std::string;

char rbuf[WBUF_SIZE];
int currentReadIndex, lengthofBuffer;

inline char read() {
	if (currentReadIndex == lengthofBuffer) { // 현재 읽는 게 끝 버퍼의 끝인 경우 다 읽은 거임
		lengthofBuffer = fread(rbuf, 1, 1 << 20, stdin);
      // rbuf[0] = 'a'
		if (!lengthofBuffer) return 0;
		currentReadIndex = 0;
	}

	return rbuf[currentReadIndex++];
   // return 'a'
   // currentIndex = 1;
}

inline int readInt() {
	int sum = 0;
	char now = read();
	bool flg = false;

	while (now <= 32) {
      now = read();
   }
	if (now == '-') {
      flg = true;
      now = read();
   }
	while (now >= 48) {
      sum = sum * 10 + now - '0';
      now = read();
   }

	return flg ? -sum : sum;
}

inline string readString() {
   string res;
   char now = read();

   while (now <= ' ') {
      now = read(); // Skip leading whitespace
   }
   while (now > ' ') { // Continue until whitespace or control character is encountered
      res += now;
      now = read();
   }

   return res;
}
