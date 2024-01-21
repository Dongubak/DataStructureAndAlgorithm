#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iomanip>

class Task {
public:
   int id;
   int st;
   int end;

   Task(int inputId, int inputStartTime, int inputEndTime) : id(inputId), st(inputStartTime), end(inputEndTime) {}

   inline bool operator<(const Task& t) const {
      if(this->end != t.end) {
         return this->end < t.end;
      } else {
         return this->st < t.st;
      }
   }

   friend std::ostream& operator<<(std::ostream& os, const Task& t) {
      std::cout << "[" << std::setw(2) << t.id << "] " << std::setw(3) << t.st << " -> " << std::setw(3) << t.end << "|";
      for(int i = 0; i < t.st; i++) {
         std::cout << " ";
      }

      for(int i = t.st; i < t.end; i++) {
         std::cout << "*";
      }

      for(int i = t.end + 1; i < 22; i++) {
         std::cout << " ";
      }

      std::cout << "|" << '\n';

      return os;
   }
};

void cal(std::list<Task> l) {
   std::vector<Task> v;
   std::cout << " [전체 작업]" << '\n';
   for(auto& t: l) {
      std::cout << t;
      v.push_back(t);
   }

   std::cout << '\n';
   std::sort(v.begin(), v.end());
      
   for(auto ptr = v.begin(); ptr < v.end() - 1; ptr++) {
      if(!(ptr->end <= (ptr + 1)->st)) {
         v.erase(ptr + 1);
         ptr--;
      }
   }

   std::cout << " [스케쥴 조정한 작업]" << '\n';
   for(auto& t: v) {
      std::cout << t;
   }
}

int main(void) {
   using namespace std;

   std::list<Task> l;
   int ids[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int st[] = {5, 6, 16, 7, 9, 10, 6, 2, 10, 4};
   int end[] = {9, 20, 19, 10, 19, 19, 12, 17, 13, 7};

   for(int i = 0; i < 10; i++) {
      l.push_back(Task(ids[i], st[i], end[i]));
   }

   cal(l);

   return 0;
}