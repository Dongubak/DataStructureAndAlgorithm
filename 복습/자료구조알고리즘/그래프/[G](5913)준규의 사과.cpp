#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::pair;

vector<vector<int>> vis;

int K;
int res;
int RR[4] = {1, -1, 0, 0};
int CC[4] = {0, 0, 1, -1};


void rec(int nj, int nh, 
pair<int, int> pj, pair<int, int> ph) {
   auto& [jcr, jcc] = pj;
   auto& [hcr, hcc] = ph;

   // if(((nj + nh) == (25 - K - 1))) {
   //    for(auto a: vis) {
   //       for(auto b: a) {
   //          cout << b << " ";
   //       }
   //       cout << '\n';
   //    }  

   //    cout << jcr << " " << jcc << '\n';
   //    cout << hcr << " " << hcc << '\n';
   //    cout << '\n';
   //    if(close(pj, ph)) {
         
   //       res += 1;
   //       return;
   //    }
   // }

   

   for(int i = 0; i < 4; i++) {
      pair<int, int> npj = {jcr + RR[i], jcc + CC[i]};
      auto& [jnr, jnc] = npj;

      if(jnr < 0 || jnr > 4 ||
         jnc < 0 || jnc > 4
      ) {
         continue;
      }

      if(vis[jnr][jnc]) {
         continue;
      }

      vis[jnr][jnc] = 1;

      for(int j = 0; j < 4; j++) {
         pair<int, int> nph = {hcr + RR[j], hcc + CC[j]};
         auto& [hnr, hnc] = nph;

         if(hnr < 0 || hnr > 4 ||
            hnc < 0 || hnc > 4
         ) {
            continue;
         }

         if(npj == nph && nj + nh >= 25 - K - 1) {
            // for(auto a: vis) {
            //    for(auto b: a) {
            //       cout << b << " ";
            //    }
            //    cout << '\n';
            // }  

            // cout << jnr << " " << jnc << '\n';
            // cout << hnr << " " << hnc << '\n';
            // cout << '\n';

            res += 1;

            continue;
         }
         
         if(vis[hnr][hnc]) {
            continue;
         }  

         vis[hnr][hnc] = 1;
         
         rec(nj + 1, nh + 1, npj, nph);
        
         
         vis[hnr][hnc] = 0;
      }

      vis[jnr][jnc] = 0;
   }
}


int main(void) {
   vis.resize(5, vector<int>(5, 0));
   int r, c;
   cin >> K;
   for(int i = 0; i < K; i++) {
      cin >> r >> c;
      vis[r - 1][c - 1] = 1; ///사과못 캠
   }

   vis[0][0] = 1;
   vis[4][4] = 1;

   rec(1, 1, {0,0}, {4, 4});
   

   cout << res;

   return 0;
}