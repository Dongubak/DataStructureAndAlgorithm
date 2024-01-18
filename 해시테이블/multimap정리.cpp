#include <iostream>
#include <map>

int main(void) {
   using namespace std;

   multimap<string, string> ma;

   string key = "James";
   string value = "Jaspers";

   ma.insert(make_pair(key, value));

   for(multimap<string, string>::iterator ptr = ma.begin(); ptr != ma.end(); ptr++) {
      cout << "key : " << ptr->first << ", value : " << ptr->second << '\n';
   }

   

   return 0;
}