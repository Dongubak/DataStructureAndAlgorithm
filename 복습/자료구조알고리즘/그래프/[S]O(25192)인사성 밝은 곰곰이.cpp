#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(void) {
   int n;
   cin >> n; cin.get();
   string chat;

   set<string> granter;

   int sum = 0;
   for(int i = 0; i < n; i++) {
      getline(cin, chat);
      if(chat == "ENTER") {
         sum += granter.size();
         granter = set<string>();
      } else {
         granter.insert(chat);
      }
   }
   sum += granter.size();

   cout << sum;

   return 0;
}