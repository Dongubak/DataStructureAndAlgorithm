#include <bits/stdc++.h>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   int n, tmp;
   string dir;
   deque<int> q;
   cin >> n;

   for(int i = 0; i < n; i++) {
      cin >> dir;
      if(dir == "push") {
         cin >> tmp;
         cin.get();

         q.push_front(tmp);
      } else if(dir == "pop") {
         if(q.empty()) {
            cout << -1 << '\n';
         } else {
            cout << q.back() << '\n';
            q.pop_back();
         }
      } else if(dir == "size") {
         cout << q.size() << '\n';
      } else if(dir == "empty") {
         if(q.empty()) {
            cout << 1 << '\n';
         } else {
            cout << 0 << '\n';
         }
      } else if(dir == "front") {
         if(q.empty()) {
            cout << -1 << '\n';
         } else {
            cout << q.back() << '\n';
         }
      } else if(dir == "back") {
         if(q.empty()) {
            cout << -1 << '\n';
         } else {
            cout << q.front() << '\n';
         }
      }
   }

   return 0;
}