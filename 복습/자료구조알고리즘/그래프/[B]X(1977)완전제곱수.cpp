#include <iostream>
using namespace std;

struct info {
   string name;
   int year;
   int month;
   int day;

   info(string n = " ", int d = 0, int m = 0, int y = 0) : year(y), month(m), day(d), name(n) {}


   bool operator>(const info& other) const {
      if(year > other.year) {
         return true;
      } else if(year < other.year) {
         return false;
      } else {
         if(month > other.month) {
            return true;
         } else if(month < other.month) {
            return false;
         } else {
            if(day > other.day) {
               return true;
            } else {
               return false;
            }
         }
      }
   }
};

int main(void) {
   int n;
   cin >> n;
   info tmp;

   info MAX(" ", 0, 0, -1);
   info MIN(" ", 0, 0, 100000000);

   for(int i = 0; i < n; i++) {
      cin >> tmp.name >> tmp.day >> tmp.month >> tmp.year;
      cin.get();

      if(tmp > MAX) {
         MAX = tmp;
      }

      if(MIN > tmp) {
         MIN = tmp;
      }
   }

   cout << MAX.name << '\n' << MIN.name << '\n';

   return 0;
}