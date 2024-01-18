#include <iostream>
#include <map>

int main(void) {
   int n, m;
   std::string input;
   std::cin >> n >> m;
   std::cin.get();
   std::map<std::string, bool> ma;
   for(int i = 0; i < n; i++) {
      getline(std::cin, input);
      ma[input] = true;
   }
   int count = 0;
   for(int j = 0; j < m; j++) {
      getline(std::cin, input);
      if(ma[input]) {
         count++;
      }
   }

   printf("%d", count);

   return 0;
}