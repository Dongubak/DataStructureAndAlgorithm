#include <iostream>
#include <set>
using namespace std;

struct CCom{
   bool operator()(const string& s1, const string& s2) const {
      if(s1.length() == s2.length()) {
         return s1 < s2;
      }

      return s1.length() < s2.length();
   }
};

int main(void) {
   int n;
   string in;
   cin >> n;

   set<string, CCom> v;

   for(int i = 0; i < n; i++) {
      cin >> in;
      v.insert(in);
   }

   for(auto& a: v) {
      cout << a << '\n';
   }


   return 0;
}