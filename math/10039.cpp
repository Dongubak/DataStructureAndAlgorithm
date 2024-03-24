#include <iostream>
using namespace std;

int main(void) {
   int t, s = 0;

   for(int i = 0; i < 5; i++) {
      cin >> t;
      s += t < 40 ? 40 : t;
   }

   cout << s / 5;

   return 0;
}