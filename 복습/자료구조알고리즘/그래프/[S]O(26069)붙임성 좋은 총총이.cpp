#include <iostream>
#include <set>

using namespace std;

int main(void) {
   int n;
   string t1, t2;
   cin >> n;

   cin.get();
   set<string> dancingList;
   bool isDanceOn = false;

   for(int i = 0; i < n; i++) {
      cin >> t1 >> t2;

      if((t1 == "ChongChong" || t2 == "ChongChong") && !isDanceOn) {
         isDanceOn = true;
         dancingList.insert(t1);
         dancingList.insert(t2);
         continue;
      }

      if(!isDanceOn) {
         continue;
      }

      if(dancingList.find(t1) != dancingList.end() || dancingList.find(t2) != dancingList.end()) {
         dancingList.insert(t1);
         dancingList.insert(t2);
      }
   }

   cout << dancingList.size();

   return 0;
}