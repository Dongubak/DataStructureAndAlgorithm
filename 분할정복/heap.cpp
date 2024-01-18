#include <iostream>
#include <unordered_map>
#include <unordered_set>

void print(const std::unordered_set<int>& container) {
   for(const auto& element : container) {
      std::cout << element << " ";
   }
   std::cout << '\n';
}

void print(const std::unordered_map<int, int>& container) {
   for(const auto& element : container) {
      std::cout << "key : " << element.first << ", value : " << element.second << " ";
   }
   std::cout << '\n';
}

void find(const std::unordered_map<int, int>& container, const int element) {
   auto iter = container.find(element);

   if(iter == container.end()) {
      std::cout << "find " << element << '\n';
   } else {
      std::cout << "cannot find " << element << '\n';
   }
}

int main(void) {
   using namespace std;

   unordered_map<int, int> m;
   unordered_set<int> s = {1, 2, 3, 4, 5};

   m[3] = 1;
   m[4] = 100;

   find(m, 3);
   find(m, 10);

   s.insert(10);
   s.insert(100);

   for(auto ptr = s.begin(); ptr != s.end(); ptr++) {
      cout << *ptr << " ";
   }
   cout << '\n';

   

   return 0;
}