#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
   double H, W, N, M;

   cin >> H >> W >> N >> M;

   int a = ceil(W / (M + 1));
   int b = ceil(H / (N + 1));
   
   cout << a * b;

   return 0;
}