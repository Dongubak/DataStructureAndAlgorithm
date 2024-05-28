#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

   int n;
   cin >> n;
   int s = 0;
   ///약수의 개수가 홀수개 즉 제곱수의 수를 구하는 방법은
   ///sqrt(2) ~ sqrt(n)까지의 개수를 구하면 된다.
   for(int i = 1; i * i <= n; i++) {
      s += 1;
   }
   cout << s;

   return 0;
}