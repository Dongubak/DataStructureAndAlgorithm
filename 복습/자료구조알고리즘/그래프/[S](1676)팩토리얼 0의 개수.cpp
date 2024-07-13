#include <iostream>

using std::cout;
using std::cin;

int main(void) {
   int N;
   cin >> N;
   int sum = 0;
   if(N >= 100) {
      sum += (N / 5 - 100 / 5) * 3;
      sum += ((N % 100) / 5 - 10 / 5) * 2;
      sum += ((N % 10) / 5);
   } else if(N >= 10){
      sum += ((N % 100) / 5 - 10 / 5) * 2;
      sum += ((N % 10) / 5);
   } else {
      sum += ((N % 10) / 5);
   }

   cout << sum;

   return 0;
}