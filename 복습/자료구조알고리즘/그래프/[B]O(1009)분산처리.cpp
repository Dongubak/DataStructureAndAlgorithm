#include <iostream>

using std::cin;
using std::cout;

void sol(void) {
   int a, b;
   cin >> a >> b;

   if(a == 1) {
      cout << 1 << '\n';
      return;
   } else if(a % 10 == 0){
      cout << 10 << '\n';
      return;
   } else {
      int s = 1;
      int c[10]{0};
      int e[10]{0};
      int k = 0;
      for(int i = 0; i < 10; i++) {
         s *= a; /// a를 계속 곱해감
         s = s % 10;

         if(c[s] == 1) {
            break;
         } else {
            c[s] = 1;
            e[k] = s;
            k++;
         }
         
      }
      // cout << "ffffffff" << '\n';
      // for(int i = 0; i < 10; i++) {
      //    cout << e[i] << '\n';
      // }
      // cout << "ffffffff" << '\n';
      // cout << "k : " << k << '\n';
      
      b = b % k;
      
      if(b == 0) {
         cout << e[k - 1] << '\n';
      } else {
         cout << e[b - 1] << '\n';
      }
   
   }
}

int main(void) {
   int n;
   cin >> n;

   for(int i = 0; i < n; i++) {
      sol();
   }

   return 0;
}