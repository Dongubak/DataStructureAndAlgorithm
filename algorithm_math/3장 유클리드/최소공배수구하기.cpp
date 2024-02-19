#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
   int m = a * b;
   while(a && b) {
      if (a > b) {
         a = a % b;
      } else {
         b = b % a;
      }
   }

   return a ? m / a : m / b;
}

int sol(vector<int>& k) {
   int prev = 0;
   
   for(int i = 0; i < k.size() - 1; i++) {
      if(i == 0) {
         prev = lcm(k[i], k[i + 1]);
      } else {
         prev = lcm(prev, k[i + 1]);
      }
   }

   return prev;
}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, t;
   cin >> n;
   vector<int> k(n);
   for(int i = 0; i < n; i++) {
      cin >> t;
      k[i] = t;
   }

   cout << sol(k);

   return 0;
}