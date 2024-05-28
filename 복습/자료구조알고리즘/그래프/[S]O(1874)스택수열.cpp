#include <iostream>
#include <stack>
#include <list>
using namespace std;

int main(void) {

   int n, m, k = 0;
   ///m은 제시된 상태
   ///k는 이전 값
   cin >> n;

   stack<int> s;
   list<char> l;

   for(int i = 1; i <= n; i++) {
      cin >> m;

      if(k < m) {
         for(int j = k + 1; j <= m; j++) {
            s.push(j);
            l.push_back('+');
         }
      }

      if(s.top() != m) {
         cout << "NO" << '\n';
         return 0;
      }

      k = max(k, m);
      s.pop();
      l.push_back('-');
   }

   for(auto& ch: l) {
      cout << ch << '\n';
   }

   return 0;
}