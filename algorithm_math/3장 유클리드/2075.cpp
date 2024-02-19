#include <bits/stdc++.h>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, t;
   cin >> n;

   priority_queue<int> q;

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         cin >> t;
         q.push(t);
      }
   }

   for(int i = 0; i < n - 1; i++) {
      q.pop();
   }

   cout << q.top();

   return 0;
}