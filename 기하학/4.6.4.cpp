#include <iostream>
using namespace std;

int main(void) {

   int a, b, M, ret = 1;
   
   cin >> a >> b >> M;

   long long p = a;

   for(int i = 0; i < b; i++) {
      if(b & (1LL << i)) {
         ret = (ret * p) % M;
      }
      p = (p * p) % M;
   }

   cout << ret;

   return 0;
}

