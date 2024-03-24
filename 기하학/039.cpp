#include <iostream>
#include <vector>
using namespace std;


int main(void) {
   int N, x;
   int l, r, h;

   cin >> N >> x;

   vector<int> s(N, 0);

   for(int i = 0; i < N; i++) {
      cin >> l >> r >> h;

      for(int i = l - 1; i < r; i++) {
         s[i] += h;
      }
   }

   for(int i = 0; i < N - 1; i++) {
      if(s[i] < s[i + 1]) {
         cout << '<';
      } else if(s[i] > s[i + 1]) {
         cout << '>';
      } else {
         cout << '=';
      }
   }

   return 0;
}