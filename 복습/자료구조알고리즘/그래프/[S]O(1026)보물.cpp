#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
   int N;
   cin >> N;
   vector<int> A(N), B(N);

   for(int i = 0; i < N; i++) {
      cin >> A[i];
   }

   for(int i = 0; i < N; i++) {
      cin >> B[i];
   }

   sort(A.begin(), A.end());
   sort(B.begin(), B.end(), [](int first, int second) -> bool {
      return first > second;
   });

   int s = 0;

   for(int i = 0; i < N; i++) {
      s += A[i] * B[i];
   }

   cout << s;

   return 0;
}