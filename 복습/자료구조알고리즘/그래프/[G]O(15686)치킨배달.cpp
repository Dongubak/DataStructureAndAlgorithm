#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int h, c;
int msum = 10e8;
void recur(vector<pair<int, int>>& c,
           vector<pair<int, int>>& h,
           vector<pair<int, int>> s,
          int i, int psum, int sn) {
   if(sn > M || i > ::c) {
      if(msum > 0 && psum > 0) {
         msum = min(msum, psum);
      } else if(msum < 0 && psum > 0) {
         msum = psum;
      }

      return;
   }

   recur(c, h, s, i + 1, psum, sn);

   s.push_back(c[i]);

   int nsum = 0;

   for(int i = 0; i < ::h; i++) {
      int tmin = 10e8;
      
      for(int j = 0; j < sn; j++) {
         int ax = abs(h[i].first - s[j].first);
         int ay = abs(h[i].second - s[j].second);
         tmin = min(ax + ay, tmin);
      }

      nsum += tmin;
   }

   recur(c, h, s, i + 1, nsum, sn + 1);
}

void sol(vector<pair<int, int>>& h, vector<pair<int, int>>& c) {
   recur(c, h, vector<pair<int, int>>(), 0, 10e8, 0);
}

int main(void){
   int t;
   cin >> N >> M;

   vector<pair<int, int>> h, c;

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         cin >> t;

         if(t == 1) {
            h.push_back(make_pair(i, j));
            ::h++;
         } else if(t == 2) {
            c.push_back(make_pair(i, j));
            ::c++;
         }
      }
   }

   sol(h, c);

   cout << msum;

   return 0;
}