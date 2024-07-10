#include <cstdio>

#define WBUF_SIZE (1 << 20)

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

bool sol(int& n, int L) {
   int m;
   int cn = n;
   for(int M = 1000000; M >= 1; M /= 10) {
      if(cn / M) {
         m = M;
         break;
      }
   }

   for(int i = m; i >= 1; i /= 10) {
      if(cn / i == L) {
         n += (i - 1);
         return false;
      }

      cn = cn % i;
   }

   return true;
}

int main(void) {

   int N, L;
   int n = 1;
   N = readInt();
   L = readInt();

   for(int i = 0; i < N; i++) {
      while(!sol(++n, L));
   }
   

   printf("%d", n);

   return 0;
}