#include <iostream>
#include <string>

using namespace std;

int nrecur = 0;

int recursion(string::iterator s, string::iterator e){
   nrecur++;
   if(s >= e) return 1;
   else if(*s != *e) return 0;
   else return recursion(s + 1, e - 1);
}

int isPalindrome(string& s){
   return recursion(s.begin(), s.end() - 1);
}

int main() {

   int n;
   string in;
   cin >> n;

   for(int i = 0; i < n; i++) {
      cin >> in;

      cout << isPalindrome(in) << " " << nrecur << '\n';

      ::nrecur = 0;
   }

   return 0;
}