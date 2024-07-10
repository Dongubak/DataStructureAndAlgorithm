#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;

int main(void) {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(NULL);
   
   int N, t;
   cin >> N;
   string in;
   
   for(int i = 0; i < N; i++) {
      int c = 0;
      cin >> t >> in;
      for(int i = 0; i < in.size() - 1; i++) {
         if(in[i] == in[i + 1] && in[i] == 'A') { // AA
            c += 2;
         } else if(in[i] == 'A' && in[i] != in[i + 1]) { /// AB
            if(in[i + 2] == 'A') { // ABA
               c += 1;
            }
         }
      }

      cout << "Case #" << i + 1 << endl << c << endl;
   }
   

   

   return 0;
}