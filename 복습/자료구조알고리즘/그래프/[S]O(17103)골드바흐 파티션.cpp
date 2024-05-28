#include <iostream>
#include <string.h>

using namespace std;

int p[1000000 + 1];

int main(void) {
   memset(p, 1, sizeof(p));

   p[0] = 0;
   p[1] = 0;

   for(int i = 2; i * i <= 1000000; i++) {
      if(p[i]) { ///i가 소수인 경우 i를 제외한 i의 배수를 제거함
         for(int j = i * i; j <= 1000000; j = j + i) {
            p[j] = 0;
         }
      }
   }

   int n, t;
   cin >> n;

   for(int i = 0; i < n; i++) {
      int s = 0;
      cin >> t;

      for(int j = 2; j <= t / 2; j++) {
         if((p[j] && p[t - j])) {
            s += 1;
         }
      }

      cout << s << '\n';
   }


   return 0;
}