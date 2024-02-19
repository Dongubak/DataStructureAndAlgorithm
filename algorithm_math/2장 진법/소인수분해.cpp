#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void) {
   
   ll n;
   cin >> n;

   for(ll i = 2; i <= n; i++) {
      while(n % i == 0) {
         cout << i << '\n';
         n /= i;
      }
   }

   return 0;
}