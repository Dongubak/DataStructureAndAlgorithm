#include <iostream>
#include <vector>
using namespace std;

int sol(vector<int>& n) {
   int gm = n[0];
   int cm = n[0];

   for(int i = 1; i < n.size(); i++) {
      cm = max(n[i], cm + n[i]);
      ///현재 원소부터 다시 시작할 지, 기존의 집합에 현재 원소를 추가하여 사용할 지
      gm = cm > gm ? cm : gm;
   }

   return gm;
}

int main() {
   int n;
   cin >> n;

   vector<int> m(n);

   for(int i = 0; i < n; i++) {
      cin >> m[i];
   }

   cout << sol(m);

   return 0;
}
