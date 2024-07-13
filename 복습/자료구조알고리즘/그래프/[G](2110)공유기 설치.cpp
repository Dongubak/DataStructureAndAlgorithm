#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;

int N, C;

bool isValid(const vector<int>& h, int mid, int C) {
   int count = 1;
   int prev = h[0];
   for (int i = 1; i < h.size(); ++i) {
      if (h[i] - prev >= mid) {
         prev = h[i];
         count++;
         if (count == C) {
            return true;
         }
      }
   }
   return false;
}

int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> C;

   vector<int> h(N);
   for(int i = 0; i < N; i++) {
      cin >> h[i];
   }

   std::sort(h.begin(), h.end());

   int l = 1, r = 1000000000;
   int optL = 0;

   while (l <= r) {
      int mid = (l + r) / 2;

      if (isValid(h, mid, C)) {
         optL = mid;
         l = mid + 1;
      } else {
         r = mid - 1;
      }
   }

   cout << optL << "\n";

   return 0;
}
