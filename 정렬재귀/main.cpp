#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int & b) {
   int tmp = a;
   a = b;
   b = tmp;
}

int main(void) {
   vector<int> a = {50, 13, 34, 75, 62, 20, 28, 11};

   for(int i = 0; i < a.size(); i++) {
      for(int j = 0; j < a.size(); j++) {
         if(a[i] < a[j]) {
            swap(a[i], a[j]);
         }
      }
   }

   for(int i = 0; i < a.size(); i++) {
      cout << a[i] << " ";
   }

   return 0;
}