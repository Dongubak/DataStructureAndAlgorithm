#include <bits/stdc++.h>
#define vt vector<int>
#define dq deque<int>
using namespace std;


int main(void) {
   int n;
   cin >> n;

   dq q;

   for(int i = int(pow(n, 0.5)); i > 0; i--) {
      if(n % i == 0) {
         q.emplace_front(i);
         if(i * i != n) {
            q.emplace_back(n / i);
         }
      }
   }

   for(int i = 0; i < q.size(); i++) {
      cout << q[i] << " ";
   }

   return 0;
}