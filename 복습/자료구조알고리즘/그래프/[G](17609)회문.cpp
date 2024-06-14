#include <iostream>
using namespace std;

bool isPalin(string& in, int& i, int& j) {
   while(i < j) {
      if(in[i] != in[j]) {
         return false;
      }
      i++, j--;
   }

   return true; ///팰린드롬
}

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   int N;
   string in;
   cin >> N;

   for(int i = 0; i < N; i++) {
      cin >> in;

      int l = 0, r = in.size() - 1;
      if(isPalin(in, l, r)) {
         cout << 0 << '\n';
      } else {
         int sl = l, sr = r;
         if(isPalin(in, ++sl, sr) || isPalin(in, l, --r)) {
            cout << 1 << '\n';
         } else {
            cout << 2 << '\n';
         }
      }

      
   }

   return 0;
}