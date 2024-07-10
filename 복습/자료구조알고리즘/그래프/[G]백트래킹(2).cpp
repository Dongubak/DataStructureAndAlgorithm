#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

int N, ans;

vector<int> v1;
vector<int> v2;
vector<int> v3;

void rec(int i) {
   if(i >= N) {
      ans += 1;
      return;
   }

   for(int j = 0; j < N; j++) {
      if(!v1[j] && !v2[i + j] && !v3[i - j + N]) {
         v1[j] = v2[i + j] = v3[i - j + N] = 1;
         rec(i + 1);
         v1[j] = v2[i + j] = v3[i - j + N] = 0;
      }
   }
}

int main(void) {
   cin >> N;

   v1.resize(N, 0);
   v2.resize(2 * N, 0);
   v3.resize(2 * N, 0);

   rec(0);

   cout << ans;

   return 0;
}