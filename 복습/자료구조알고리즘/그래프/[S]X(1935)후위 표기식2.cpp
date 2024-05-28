#include <iostream>
#include <list>
#include <cstdlib>
#include <stack>

using namespace std;

void sol(string& input, vector<int>& m) {
   list<char> l;
   for(auto& ch: input) {
      l.push_back(ch);
   }
   
   while(l.size() != 1) {
      stack<char> s;
      while(isalpha(l.front())) { ///Alphabet
         s.push(l.front());
         l.pop_front();
      }
      int a1, a2;
      a1 = m[s.top() - 'A']; s.pop();
      a2 = m[s.top() - 'A']; s.pop();
      switch(l.front()) {
         case '+':
            s.push(a1 + a2);
            break;
         case '-':
            s.push(a1 - a2);
            break;
         case '*':
            s.push(a1 * a2);
            break;
         case '/':
            s.push(a1 / a2);
            break;
      }

      l.pop_front();

      while(!s.empty()) {
         l.push_front(s.top());
         s.pop();
      }
   }

   cout << l.front();
}

int main(void) {
   int n, t;
   cin >> n;

   string input;
   cin >> input;

   vector<int> m(n);

   for(int i = 0; i < n; i++) {
      cin >> m[i];
   }

   sol(input, m);

   return 0;
}