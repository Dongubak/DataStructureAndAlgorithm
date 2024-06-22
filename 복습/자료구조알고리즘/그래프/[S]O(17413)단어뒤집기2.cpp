#include <iostream>

using std::cin;
using std::cout;

void outTag() {
   char in;

   cout << '<';

   while(!cin.eof() && (in = cin.get()) && in != '>') {
      cout << in;
   }

   cout << '>';
}

int main(void) {
   cin.tie(NULL);
   std::ios_base::sync_with_stdio(false);
   char in;

   while(cin) {
      std::string sin;
      while(!cin.eof() && (in = cin.get()) && in != ' ' && in != '<') {
         sin.push_back(in);
      }


      if(sin.size() != 0) {
         for(int i = sin.size() - 1; i >= 0; i--) {
            if(sin[i] != EOF && sin[i] != '\n') {
               cout << sin[i];
            }
         }
      }

      if(in == ' ') {
         cout << ' ';  
      }

      if(in == '<') {
         outTag();
      }
   }

   return 0;
}