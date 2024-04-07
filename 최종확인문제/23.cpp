#include <iostream>
#include <vector>
using namespace std;

void sol(vector<int>& n, long long L, long long R) {
   if(L == 1) {
      n[0] = 0;
   }

   for(long long i = 2; i * i <= R; i++) {
      long long min_value = ((L + i - 1) / i) * i;

      for(long long j = min_value; j <= R + 1; j = j + i) {
         if(j == i) {
            continue;
         }

         n[j - L] = 0;
      }
   }

   int c = 0;
   for(long long i = 0; i < R - L + 1; i++) {
      if(n[i] == 1) {
         c++;
      }
   }

   cout << c;
}

int main(void) {
   long long L, R;
   cin >> L >> R;

   vector<int> n(R - L + 1, 1);

   sol(n, L, R);

   return 0;
}