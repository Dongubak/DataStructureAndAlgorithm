#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
   int t;
   cin >> t;

   for(int i = 0; i < t; i++) {
      int n1, n2;
      cin >> n1;

      vector<int> m1(n1);

      for(int i = 0; i < n1; i++) {
         cin >> m1[i];
      }

      cin >> n2;
      vector<int> m2(n2);
      for(int i = 0; i < n2; i++) {
         cin >> m2[i];
      }

      sort(m1.begin(), m1.end());

      for(auto x: m2) {
         cout << binary_search(m1.begin(), m1.end(), x) << '\n';
      }
   }

   return 0;
}