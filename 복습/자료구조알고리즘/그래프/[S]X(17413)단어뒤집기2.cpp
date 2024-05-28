#include <iostream>
#include <stack>

using namespace std;

int main(void) {
   string in;
   char tmp;
   bool inBrace = false;

   while((cin >> tmp)) {
      if(tmp == '<') {
         cout << tmp;

         while(cin >> tmp) {
            cout << tmp;

            if(tmp == '>') {
               inBrace = !inBrace;
               break;
            }
         }
      } else {
         if(inBrace) {
            stack<char> s;
            while((cin >> tmp) && tmp != '<' && tmp != '') {
               s.push(tmp);
            }

            while(!s.empty()) {
               cout << s.top();
               s.pop();
            }
         } else {
            
         }
         
      }
   }

   return 0;   
}