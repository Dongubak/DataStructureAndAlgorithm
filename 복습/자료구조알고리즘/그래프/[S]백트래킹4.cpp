#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int N, S, res;
vector<int> A;

void rec(int i, long sum, int s) {
   if(i >= N) {
      if(sum == S && s > 0) {
         res += 1;
      }

      return;
   }

   rec(i + 1, sum + A[i], s + 1);
   rec(i + 1, sum, s);
}

int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> N >> S;
   A.resize(N, 0);

   for(int i = 0; i < N; i++) {
      cin >> A[i];
   }

   rec(0, 0, 0);
   cout << res;

   return 0;
}