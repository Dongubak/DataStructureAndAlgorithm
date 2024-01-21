#include <iostream>
#include <map>

int main(void) {
   using namespace std;
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int tc, c;
   string tmp1, tmp2;
   cin >> tc;

   for(int i = 0; i < tc; i++) {
      cin >> c;
      map<string, string> ma;
      cin.get();
      for(int i = 0; i < c; i++) {
         cin >> tmp1 >> tmp2;
         cin.get();
         ma[tmp1] = tmp2;

         int c = 1;
         while(1) {
            if(ma.find(tmp1) == ma.end()) {
               break;
            } else {
               tmp1 = ma[tmp1];
               c++;
            }
         }
         
         

         cout << c << '\n';
      }
   }

   return 0;
}