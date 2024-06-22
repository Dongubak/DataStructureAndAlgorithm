#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

int main(void) {
   string in;
   string out;
   int hi;
   vector<int> x(26, 0);

   cin >> in;

   for(auto ch : in) {
      x[ch - 'A'] += 1;
   }

   if(in.size() % 2 == 0) {
      for(auto& n: x) {
         if(n % 2 == 1) {
            cout << "I'm Sorry Hansoo" << '\n';
            return 0;
         }
      }

   } else {
      int c = 0;

      for(int i = 0; i < 26; i++) {
         if(x[i] % 2 == 1) {
            hi = i;
            x[i] -= 1;
            c++;
         }

         if(c == 2) {
            cout << "I'm Sorry Hansoo";
            return 0;
         }
      }
      
   }

   for(int i = 0; i < 26; i++) {
      x[i] = x[i] / 2;
      if(x[i] != 0) {
         for(int j = 0; j < x[i]; j++) {
            out.push_back('A' + i);
         }
      }
   }

   cout << out;

   if(in.size() % 2 == 1) {
      cout << char('A' + hi);
   }
   for(int i = out.size() - 1; i >= 0; i--) {
      cout << out[i];
   }

   // -'A'

   return 0;
}