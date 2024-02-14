#include <bits/stdc++.h>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   string input;
   cin >> input;
   cin.get();
   while(input != "0") {
      bool isPalin = true;
      for(int i = 0, j = input.size() - 1; i < j; i++, j--) {
         if(input[i] - 48 != input[j] - 48) {
            isPalin = false;
            break;
         }
      }

      if(isPalin) {
         cout << "yes" << '\n';
      } else {
         cout << "no" << '\n';
      }


      cin >> input;
      cin.get();
   }

   return 0;
}