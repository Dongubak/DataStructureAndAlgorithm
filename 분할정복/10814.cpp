#include <iostream>
#include <map>
#include <set>

int main(void) {

   int n, m;
   std::string tmp;
   std::cin >> n;
   std::multimap<int, std::string> ma;
   for(int i = 0; i < n; i++) {
      std::cin >> m >> tmp;
      ma.insert(make_pair(m, tmp));
   }

   for(auto ptr = ma.begin(); ptr != ma.end(); ptr++) {
      std::cout << ptr->first << " " << ptr->second << '\n';
   }
   return 0;
}