#include <bits/stdc++.h>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   string input;
   cin >> input;

   int s = input.size();

   for(int i = 1; i < s + 1; i++) {
      cout << input[i - 1];
      if(i % 10 == 0) {
         cout << '\n';
      }
   }

   return 0;
}

