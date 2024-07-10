#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using std::cin;
using std::cout;
using std::vector;
using std::map;
using std::pair;

int rec(int cur, int k, const int& y, map<pair<int, int>, int>& m) {
   if (k <= 0) {
      return 10e5;
   }

   if (cur >= y - 1) {
      if (cur == y - 1) {
         return 1;
      }
      return 10e5;
   }

   pair<int, int> state = {cur, k}; ///현재 상태에 대한 정보가 저장되어 있냐?
   if (m.find(state) != m.end()) {
   return m[state];
   }

   int right = rec(cur + (k + 1), k + 1, y, m);
   int mid = rec(cur + k, k, y, m);
   int left = (k - 1 >= 0) ? rec(cur + (k - 1), k - 1, y, m) : 10e5;

   m[state] = 1 + std::min(std::min(right, mid), left);
   return m[state];
}

void sol(const int& x, const int& y) {
   map<pair<int, int>, int> m;
   
   int result = rec(x + 1, 1, y, m);
   cout << result + 1 << '\n';
}

int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;

   for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;

      sol(x, y);
   }

   return 0;
}
