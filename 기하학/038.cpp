#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   int N, D;
   cin >> N >> D;

   vector<int> n(N);
   vector<int> s(N);
   for(int i = 0; i < N; i++) {
      cin >> n[i];
   }

   s[0] = n[0];

   for(int i = 1; i < N; i++) {
      s[i] = s[i - 1] + n[i];
   }

   int b, e;

   for(int i = 0; i < D; i++) {
      cin >> b >> e;
      cout << s[e - 1] - s[b - 2] << '\n';
   }

   return 0;
}