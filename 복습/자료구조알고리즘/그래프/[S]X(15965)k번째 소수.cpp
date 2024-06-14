#include <iostream>
#include <cstring>

using namespace std;

bool p[500000 + 1];

int main(void) {
   int n;
   cin >> n;

   memset(p, 1, sizeof(p));

   for(int i = 2; i <= 500000; i++) {
      for(int j = 2 * i; j <= 500000; j = j + i) {
         p[j] = 0;
      }
   }
   int c = 0;
   for(int i = 2; i <= 500000; i++) {
      if(p[i]) {
         c += 1;

         if(c == n) {
            cout << i;
            break;
         }
      }
   }

   return 0;
}