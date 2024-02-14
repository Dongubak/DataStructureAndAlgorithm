#include <iostream>
#include <vector>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, p;
   cin >> n >> p;

   vector<int> d(n);

   for (int i = 0; i < n; i++) {
      d[i] = i + 1;
   }
   cout << "<";
   vector<int>::iterator prev = d.begin();
   while (!d.empty()) {
      for (int i = 0; i < p - 1; i++) {
         ++prev;
         if (prev == d.end()) {
               prev = d.begin();
         }
      }

      cout << *prev;

      prev = d.erase(prev);

      if (!d.empty()) {
         cout << ", ";
         if (prev == d.end()) {
               prev = d.begin();
         }
      }
   }
   cout << ">";

    return 0;
}
