#include <iostream>
using namespace std;

int main(void) {
   int a, b;
   long ret = 1;

   cin >> a >> b;

   for(int i = 0; i < b; i++) {
      ret = (ret * a) % 1000000007;
   }

   cout << ret;

   return 0;
}