#include <bits/stdc++.h>
using namespace std;

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   vector<int> p(8);

   for(int i = 0; i < 8; i++) {
      cin >> p[i];
   }

   vector<int> as = {1, 2, 3, 4, 5, 6, 7, 8};
   vector<int> dis = {8, 7, 6, 5, 4, 3, 2, 1};


   bool isas = true;
   for(int i = 0; i < 8; i++) {
      if(as[i] != p[i]) {
         isas = false;
      }
   }


   if(!isas) {
      bool isdis = true;
      for(int i = 7; i >= 0; i--) {
         if(dis[i] != p[i]) {
            isdis = false;
         }
      }

      if(!isdis) {
         cout << "mixed";
      } else {
         cout << "descending";
      }
   } else {
      cout << "ascending";
   }

   return 0;
}