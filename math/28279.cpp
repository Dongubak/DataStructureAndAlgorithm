#include <bits/stdc++.h>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, t;
   cin >> n;

   deque<int> dq;

   for(int i = 0; i < n; i++) {
      cin >> t;

      if(t == 1) {
         cin >> t;
         dq.push_front(t);       
      } else if(t == 2) {
         cin >> t;
         dq.push_back(t);
      } else if(t == 3) {
         if(!dq.empty()) {
            cout << dq.front() << '\n';
            dq.pop_front();
         } else {
            cout << -1 << '\n';
         }
      } else if(t == 4) {
         if(!dq.empty()) {
            cout << dq.back() << '\n';
            dq.pop_back();
         } else {
            cout << -1 << '\n';
         }
      } else if(t == 5) {
         cout << dq.size() << '\n';
      } else if(t == 6) {
         if(dq.empty()) {
            cout << 1 << '\n';
         } else {
            cout << 0 << '\n';
         }
      } else if(t == 7) {
         if(!dq.empty()) {
            cout << dq.front() << '\n';
         } else {
            cout << -1 << '\n';
         } 
      } else {
         if(!dq.empty()) {
            cout << dq.back() << '\n';
         } else {
            cout << -1 << '\n';
         }
      }
   }

   return 0;
}