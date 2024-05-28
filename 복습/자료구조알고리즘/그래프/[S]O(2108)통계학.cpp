#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
   int n, t;
   cin >> n;

   vector<int> k(n);
   set<int> s;
   map<int, int> m;
   map<int, set<int>> revm;

   if(n == 1) {
      cin >> t;
      cout << t << '\n';
      cout << t << '\n';
      cout << t << '\n';
      cout << 0 << '\n';
      return 0;
   }

   for(int i = 0; i < n; i++) {
      cin >> t;
      k[i] = t;
      m[t] = m[t] + 1;
      s.insert(t);
   }


   int sum = 0;
   for(int i = 0; i < n; i++) {
      sum += k[i];
   }
   
   int p = round((double)sum / n);
   cout << p << '\n';

   sort(k.begin(), k.end());
   vector<int>::iterator iter = k.begin();

   for(int i = 0; i < n / 2; i++) {
      iter++;
   }

   cout << *iter << '\n';

   for(auto ptr = m.begin(); ptr != m.end(); ptr++) {
      revm[ptr->second].insert(ptr->first);
   }
   set<int> cs = (revm.rbegin()->second);
   if(cs.size() == 1) {
      cout << *cs.begin() << '\n';
   } else {
      set<int>::iterator iter = cs.begin();
      iter++;
      cout << *iter << '\n';
   }
   
   cout << *(s.rbegin()) - *(s.begin());


   return 0;
}