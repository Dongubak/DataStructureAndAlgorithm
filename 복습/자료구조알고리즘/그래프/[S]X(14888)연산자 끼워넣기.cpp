#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

int max;

void rec(int n, vector<int> rop, vector<int> m) {
   ///n : 연산자 개수
   ///rop: 남은 연산자 정보
   ///op: 현재 선택된 연산자 정보
   ///주어진 수: m

   if(n == m.size() - 1) {
      max = std::max(max, m.back());
      return;
   }

   /// +
   if(rop[0] != 0) {
      vector<int> nrop = rop;
      vector<int> nm = m;
      nrop[0] -= 1;
      nm[n + 1] = nm[n] * nm[n + 1];
      rec(n + 1, nrop, nm);
   }
   /// -

   if(rop[1] != 0) {
      vector<int> nrop = rop;
      vector<int> nm = m;
      nrop[1] -= 1;
      nm[n + 1] = nm[n] * nm[n + 1];

      rec(n + 1, nrop, nm);
   }
   /// x
   if(rop[2] != 0) {
      vector<int> nrop = rop;
      vector<int> nm = m;
      nrop[2] -= 1;
      nm[n + 1] = nm[n] * nm[n + 1];

      rec(n + 1, nrop, nm);
   }
   /// /
   if(rop[3] != 0) {
      vector<int> nrop = rop;
      vector<int> nm = m;
      nrop[3] -= 1;
      nm[n + 1] = nm[n] * nm[n + 1];

      rec(n + 1, nrop, nm);
   }
}

void sol(vector<int>& m, vector<int>& op) {
   rec(0, op, m);
}

int main(void) {
   int n;
   cin >> n;

   vector<int> m(n);
   vector<int> op(4);
   for(int i = 0; i < n; i++) {
      cin >> m[i];
   }

   for(int i = 0; i < 4; i++) {
      cin >> op[i];
   }

   sol(m, op);

   cout << max;

   return 0;
}