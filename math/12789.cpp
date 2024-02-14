#include <bits/stdc++.h>
using namespace std;


int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, tm;
   cin >> n;

   queue<int> q;
   stack<int> q2;

   for(int i = 0; i < n; i++) {
      cin >> tm;
      q.push(tm);
   }
   int or1 = 1;
   while(!q.empty()) {
      int pp = q.front();
      q.pop();

      if(pp == or1) {
         or1++;
      } else { //pp가 간식받는 곳으로 이동이 불가능 함
         q2.push(pp);
      }

      while(!q2.empty() && q2.top() == or1) {
         or1++;
         q2.pop();
      }
   }

   if(q2.empty()) {
      cout << "Nice";
   } else {
      cout << "Sad";
   }

   return  0;
}