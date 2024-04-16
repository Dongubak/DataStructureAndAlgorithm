#include <iostream>
#include <map>

using namespace std;

class DisjointSet {
public:
   map<string, string> founder;
   map<string, int> count;

   DisjointSet() {
      founder = map<string, string>();
   }

   string find(string s1) { ///find s1's founder;
      if(s1 == founder[s1]) {
         return s1;
      }

      return founder[s1] = find(founder[s1]);
   }

   void merge(string s1, string s2) {
      string f1 = find(s1); ///founder of s1
      string f2 = find(s2); ///founder of s2

      if(f1 != f2) {
         count[f2] += count[f1];
         founder[f1] = f2;
      }

      cout << count[find(s1)] << '\n';
   }

   void addM(string s1, string s2) {
      if(founder.find(s1) == founder.end()) {
         founder[s1] = s1;
         count[s1] = 1;
      }

      if(founder.find(s2) == founder.end()) {
         founder[s2] = s2;
         count[s2] = 1;
      }

      merge(s1, s2);
   }
};

int main(void) {

   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int t, n;
   cin >> t;

   string s1, s2;

   for(int i = 0; i < t; i++) {
      DisjointSet djs;
      cin >> n;

      for(int j = 0; j < n; j++) {
         cin >> s1 >> s2;
         djs.addM(s1, s2);
      }
   }
   


   return 0;
}