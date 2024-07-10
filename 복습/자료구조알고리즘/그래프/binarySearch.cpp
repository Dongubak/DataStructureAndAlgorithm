#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

vector<int> n;

bool linearSearch(vector<int> v, int f) {
   for(auto a : v) {
      if(a == f) {
         return true;
      }
   }

   return false;
}

bool binarySearch(vector<int> v, int p, int r, int f) {
   while(p <= r) {
      int q = (p + r) / 2;
      auto mid = v[q];
      if(mid < f) {
         p = q + 1;
      } else if(mid == f) {
         return true;
      } else {
         r = q - 1;
      }
   }
   
   return false;
}

int main(void) {
   int N;
   cin >> N;

   n.resize(N);

   for(int i = 0; i < N; i++) {
      cin >> n[i];
   }

   sort(n.begin(), n.end());

   if(linearSearch(n, 1)) {
      cout << "있음";
   } else {
      cout << "없음";
   }

   if(binarySearch(n, 0, n.size() - 1, 1)) {
      cout << "있음";
   } else {
      cout << "없음";
   }

   cout << '\n';

   return 0;
}