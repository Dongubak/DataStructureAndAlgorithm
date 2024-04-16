#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
   int n;
   cin >> n;

   vector<int> x(n); vector<int> y(n);
   

   for(int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
   }

   double min = 10e6;
   double tmp;
   for(int i = 0; i < n - 1; i++) {
      for(int j = i + 1; j < n; j++) {
         tmp = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
         if(tmp < min) {
            min = tmp;
         }
      }
   }

   cout << min;

   return 0;
}