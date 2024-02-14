#include <bits/stdc++.h>
using namespace std;

int main(void) {

   deque<int> c;
   int n;
   cin >> n;
   // 12345
   // f   b
   for(int i = 1; i < n + 1; i++) {
      c.push_back(i);
   }
   
   // cout << c.front() << " ";
   // c.pop_front();
   
   // cout << c.front() << " ";

   while(c.size() != 1) {
      c.pop_front();
      c.push_back(c.front());
      c.pop_front();
   }

   cout << c.front();

   return 0;
}