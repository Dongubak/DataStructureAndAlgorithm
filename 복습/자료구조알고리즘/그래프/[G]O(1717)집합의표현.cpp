#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
   vector<int> founder;

   DisjointSet(int n) {
      founder.resize(n);

      for(int i = 0; i < n; i++) {
         founder[i] = i;
      }
   }

   int find(int ch) {
      if(founder[ch] == ch) {
         return ch;
      }

      return founder[ch] = find(founder[ch]);
   }

   bool merge(int ch1, int ch2) {
      ch1 = find(ch1);
      ch2 = find(ch2);

      if(ch1 != ch2) {
         founder[ch1] = ch2;
         return true;
      } else {
         return false;
      }
   }

   void isSameFounder(int ch1, int ch2) {
      if(find(ch1) == find(ch2)) {
         cout << "YES" << '\n';
      } else {
         cout << "NO" << '\n';
      }
   }
};

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   int n, qn;
   cin >> n >> qn;

   DisjointSet djs(n + 1);

   int q, u, v;
   ///q: 질문
   for(int i = 0; i < qn; i++) {
      cin >> q >> u >> v;

      if(q == 1) {
         djs.isSameFounder(u, v);
      } else {
         djs.merge(u, v);
      }
   } 

   return 0;
}