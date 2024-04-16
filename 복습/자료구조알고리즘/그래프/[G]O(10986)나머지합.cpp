#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long dp[1000];

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   int n, m, t;

   cin >> n >> m;
   vector<long long> a(n + 1);
   
   for(int i = 1; i <= n; i++) {
      cin >> t;
      a[i] = (a[i - 1] % m + t % m) % m;
      dp[a[i]] += 1;
   }
   dp[0] += 1;

   long long s = 0;
   for(int i = 0; i < m; i++) {
      s += long(dp[i] * (dp[i] - 1)) / 2;
   }

   cout << s;
   

   return 0;
}