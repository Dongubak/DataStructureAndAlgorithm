#include <iostream>
using namespace std;

int m[10000000 + 1];

int main(void) {
   m[1] = 1;
   m[2] = 1;

   int N;
   cin >> N;

   if(N < 3) {
      cout << 1;
      return 0;
   } else {
      for(int i = 3; i < N + 1; i++) {
         m[i] = (m[i - 1] + m[i - 2]) % 1000000007;
      }
   }

   cout << m[N];

   return 0;
}