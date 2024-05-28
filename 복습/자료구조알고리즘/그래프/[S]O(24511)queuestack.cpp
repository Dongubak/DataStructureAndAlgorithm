#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   deque<int> dq;
   int n, t;
   cin >> n;

   vector<int> type(n);
   for(int i = 0; i < n; i++) {
      cin >> type[i];
   }

   for(int i = 0; i < n; i++) {
      cin >> t;
      if(type[i] == 0) {
         dq.emplace_front(t);
      }
   }

   int m;
   cin >> m;
   vector<int> insertData(m);

   for(int i = 0; i < m; i++) {
      cin >> insertData[i];
   }

   for(int i = 0; i < m; i++) {
      dq.emplace_back(insertData[i]);
      cout << dq.front() << '\n';
      dq.pop_front();
   }

   

   return 0;

}