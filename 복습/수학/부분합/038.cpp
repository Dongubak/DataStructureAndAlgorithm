#include <iostream>
using namespace std;

int main(void) {
   int n, q;
   ///n은 일당 입장수
   ///q는 질문 수

   cin >> n >> q;

   vector<int> a(n + 1, 0);
   vector<int> b(n + 1, 0);
   for(int i = 1; i < n + 1; i++) {
      cin >> a[i];
   }

   for(int i = 1; i < n + 1; i++) {
      b[i] = b[i - 1] + a[i];
   }

   int l, r;

   for(int i = 0; i < q; i++) {
      cin >> l >> r;

      cout << b[r] - b[l - 1] << '\n';
   }

   return 0;
}