#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
int n;
vector<int> vis;

void plus(int& j) {
   j = j + 1;
   if(j >= n) {
      j = 0;
   }

   while(vis[j]) {
      j = j + 1;
      if(j >= n) {
         j = 0;
      }
   }
}

int main(void) {
   int o;
   cin >> n >> o;

   int c = 0;
   int j = 0;
   vis.resize(n);

   for(int i = 0; i < o - 1; i++) {
      plus(j);
   }
   vis[j] = 1;
   
   c++;

   if(c == n) {
      cout << '<' << j + 1 << '>';
   } else {
      cout << '<' << j + 1 << ", ";
   }

   while(c != n) {
      for(int i = 0; i < o; i++) {
         plus(j);
      }

      vis[j] = 1;
      if(c == n - 1) {
         cout << j + 1 << '>';   
      } else {
         cout << j + 1 << ", ";
      }
      
      c++;
   }

   return 0;
}