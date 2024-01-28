#include <cstdio>

int main(void) {
   using namespace std;

   int n, H, W, N;
   int f = 0, b = 1;
   scanf("%d", &n);
   for(int i = 0; i < n; i++) {
      scanf("%d %d %d", &H, &W, &N);
      // N / H 만큼 뒤에 두자리 증가
      // N % H 만큼 앞에 숫자 증가
      // 예시 
      f += N % H;
      b += N / H;
      printf("%d", f ? f : H);
      if(b < 10) {
         printf("0%d", b);
      } else {
         printf("%d", b);
      }
      printf("\n");

      f = 0, b = 1;
   }

   return 0;
}