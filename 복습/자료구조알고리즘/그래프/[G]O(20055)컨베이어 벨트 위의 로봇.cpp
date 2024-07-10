#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
using std::vector;

int N, L;
vector<pair<int, int>> c;
// 내구도, 로봇 여부

bool isDone() {
   int count = 0;

   for(int i = 0; i < 2 * N; i++) {
      if(c[i].first == 0) {
         count++;
      }
   }

   if(count >= L) {
      return true;
   } else {
      return false;
   }
}

void sol() {
   int page = 0;
   int k = 0;
   int d;
   do {
      k--, page++;
      if(k < 0) {
         k = 2 * N - 1;
      }
      d = k + N - 1;
      
      if(d > 2 * N - 1) {
         d = k - N - 1;
      }
      // cout << "k : " << k << ", d : " << d << '\n';

      if(c[d].second == 1) {
         c[d].second = 0;
      }


      int j = d;
      for(int i = 0; i < N - 1; i++) {
         int p = j - 1;
         if(p < 0) {
            p = 2 * N - 1;
         }
         // cout << "p : " << p << '\n';
         if(c[j].first > 0 && c[j].second == 0 && c[p].second == 1) {
            c[j].first -= 1;
            c[p].second = 0, c[j].second = 1;
         }
         j--;
         if(j < 0) {
            j = 2 * N - 1;
         }
      }

      if(c[d].second == 1) {
         c[d].second = 0;
      }

      if(c[k].first > 0) {
         c[k].first -= 1;
         c[k].second = 1;
      }

      // for(int i = 0; i < 2 * N; i++) {
      //    cout << c[i].first << " ";
      // }
      // cout << '\n';
   } while(!isDone());

   cout << page;
}

int main(void) {
   int t;
   cin >> N >> L;

   c.resize(2 * N, pair<int, int>());   

   for(int i = 0; i < 2 * N; i++) {
      cin >> t;
      c[i] = {t, 0};
   }

   sol();

   return 0;
}