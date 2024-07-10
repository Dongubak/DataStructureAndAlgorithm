#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::pair;

vector<vector<int>> map;
vector<pair<int, int>> hall;

void rec(int n) {
   if(n >= hall.size()) {
      // 조사
      for(int i = 0; i < 9; i++) {
         for(int j = 0; j < 9; j++) {
            cout << map[i][j] << " ";
         }
         cout << '\n';
      }
      exit(0);
   }

   const auto& [oi, oj] = hall[n];
   // cout << oi << " " << oj << '\n';
   int ni, nj;

   for(int i = 0; i < 3; i++) {
      if(oi >= i * 3 && oi < (i + 1) * 3) {
         ni = i;
      }

      if(oj >= i * 3 && oj < (i + 1) * 3) {
         nj = i;
      }
   }

   // cout << ni << " " << nj << '\n';

   vector<int> vis(9, 0);

   for(int i = 0; i < 9; i++) {
      if(map[oi][i]) {
         vis[map[oi][i] - 1] = 1;
      }
   }

   for(int i = 0; i < 9; i++) {
      if(map[i][oj]) {
         vis[map[i][oj] - 1] += 1;
      }
   }

   for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
         if(map[3 * ni + i][3 * nj + j]) {
            vis[map[3 * ni + i][3 * nj + j] - 1] += 1;
         }
      }
   }

   for(int i = 0; i < 9; i++) {
      if(!vis[i]) {
         map[oi][oj] = i + 1;
         rec(n + 1);
         map[oi][oj] = 0;
      }
   }

   
}

int main(void) {
   map.resize(9, vector<int>(9, 0));

   for(int i = 0; i < 9; ++i) {
      for(int j = 0; j < 9; ++j) {
         cin >> map[i][j];
         if(map[i][j] == 0) {
            hall.push_back({i, j});
         }
      }
   }

   rec(0);

   return 0;
}