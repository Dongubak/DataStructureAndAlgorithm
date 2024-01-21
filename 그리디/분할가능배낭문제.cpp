#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Object {
public:
   int id;
   int weight;
   double value;
   double value_per_unit_weight;
   Object(int i, int w, double v) : id(i), weight(w), value(v), value_per_unit_weight(v / w){}
   inline bool operator<(const Object& obj) const {
      ///operator사용시에 value_per_unit_weight기준으로 객체들을 오름차순으로 정렬한다.
      return this->value_per_unit_weight < obj.value_per_unit_weight;
   }
   friend std::ostream& operator<<(std::ostream& os, const Object& obj) {
      os << "[" << obj.id << "] 가격 : " << obj.value << " \t무게 : " << obj.weight << " kg\t단위 무게 당 가격 : " << obj.value_per_unit_weight;
      return os;
   }
};

std::vector<Object> fill_knapsack(std::vector<Object>& objects, int knapsack_capacity) {
   std::vector<Object> knapsack_contents;
   knapsack_contents.reserve(objects.size());

   std::sort(objects.begin(), objects.end());
   std::reverse(objects.begin(), objects.end());

   auto current_object = objects.begin();
   int current_total_weight = 0;
   while(current_total_weight < knapsack_capacity &&
         (current_total_weight + current_object->weight) <= knapsack_capacity &&
         current_object != objects.end()
   ) { ///용량보다 적으며 끝이 아님
      knapsack_contents.push_back(*current_object);

      current_total_weight += current_object->weight;
      current_object++; ///move to next iterator
   }

   return knapsack_contents;
}

int main(void) {
   std::vector<Object> objects;
   objects.reserve(7);

   std::vector<int> weights = {1, 2, 5, 9, 2, 3, 4};
   std::vector<double> values = {10, 7, 15, 10, 12 ,11, 5};

   for(int i = 0; i < 7; i++) {
      objects.push_back(Object(i + 1, weights[i], values[i]));
   }

   std::cout << "[사용할 수 있는 물건 정보]" << '\n';
   for(auto& o: objects) {
      std::cout << o << '\n';
   }
   std::cout << '\n';

   int knapsack_capacity = 7; ///최대 허용 무게를 7로 지정한다.

   auto solution = fill_knapsack(objects, knapsack_capacity);

   std::cout << "[배낭에 넣을 물건들 (최대 용량 = " << knapsack_capacity << ")]" << '\n';

   for(auto& o : solution) {
      std::cout << o << '\n';
   }
   std::cout << '\n';
}