#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main(void) {
   int n, w, L;

   cin >> n >> w >> L;

   vector<int> t(n);

   for(int i = 0; i < n; i++) {
      cin >> t[i];
   }

   int k = 0;
   int count = 0;
   int time = 0;
   while(k < n) {
      int prevK = k - 1;
      int sum = 0;
      
      int onBrid = 0;
      for(int i = k; i < n; i++) {
         if(sum + t[i] <= L) {
            sum += t[i];
            k++;
            onBrid++;
         } else {
            break;
         }
      }

      // cout << "k : " << k << '\n';
      // cout << "onBrid : " << onBrid << '\n';
      if(k + 1 < n && t[prevK] + t[k] > L) {
         time -= 1;
      } else {
         if(k + 1 < n) {
            time -= 2;
         }
      }
      time += (onBrid + w);
      count++;
   }
   // cout << "time : " << time << '\n';

   // cout << "count : " << count << '\n';

   cout << time;
   return 0;
}