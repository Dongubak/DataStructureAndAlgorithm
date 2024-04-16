#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   
   int n;
   cin >> n;

   vector<int> pos(n);
   priority_queue<int, vector<int>, greater<int>> pq;
   map<int, int> ma;

   for(int i = 0; i < n; i++) {
      cin >> pos[i];
      pq.push(pos[i]);
   }

   int st = 0;

   while(!pq.empty()) {
      int t = pq.top();
      pq.pop();

      if(ma.find(t) == ma.end()) {
         ma[t] = st++;
      }
   }  

   for(int i = 0; i < n; i++) {
      cout << ma[pos[i]] << " ";
   }

   return 0;
}