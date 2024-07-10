#include <iostream>
#include <vector>
#include <tuple>

using std::cin;
using std::cout;
using std::vector;
using std::tuple;

int RR[] = {-1, 0, 1, 0};
int CC[] = {0, 1, 0, -1};
int R, C;
vector<vector<int>> s;

bool isCleanable(tuple<int, int, int> cur) {
   auto [cr, cc, cd] = cur;
   for(int j = 0; j < 4; j++) {
      if(cr + RR[j] >= 0 && cr + RR[j] < R &&
         cc + CC[j] >= 0 && cc + CC[j] < C &&
         s[cr + RR[j]][cc + CC[j]] == 0
         ) {
         return true;
      }
   }

   return false;
}

void sol(tuple<int, int, int> cur) {
   int res = 0;
   auto& [cr, cc, cd] = cur;

   while(1) {
      if(s[cr][cc] == 0) {
         res += 1;
         s[cr][cc] = 2; /// 청소완룡
      }

      if(isCleanable(cur)) {
         for(int j = 0; j < 4; j++) {
            cd = cd - 1;
            if(cd == -1) {
               cd = 3;
            }

            if(
               s[cr + RR[cd]][cc + CC[cd]] == 0) {
               cr += RR[cd];
               cc += CC[cd];
               break;
            }
         }
      } else {
         int nr = cr - RR[cd], nc = cc - CC[cd];
         if(nr >= 0 && nr < R && 
            nc >= 0 && nc < C &&
            s[nr][nc] != 1
         ) {
            cr = nr;
            cc = nc;
         } else {
            cout << res;
            return;
         }
      }
   }
}

int main(void) {
   cin >> R >> C;

   s.resize(R, vector<int>(C, 0));

   tuple<int, int, int> cur;
   auto& [r, c, d] = cur;
   cin >> r >> c >> d;
   
   for(int i = 0; i < R; i++) {
      for(int j = 0; j < C; j++) {
         cin >> s[i][j];
      }
   }

   sol(cur);

   return 0;
}