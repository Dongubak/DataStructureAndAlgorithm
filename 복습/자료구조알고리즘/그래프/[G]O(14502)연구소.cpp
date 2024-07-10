#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::queue;

int N, M;
vector<vector<int>> L;
vector<pair<int, int>> V;
vector<pair<int, int>> B;

int RR[4] = {1, -1, 0, 0};
int CC[4] = {0, 0, 1, -1};

int max = -1;

void split(vector<pair<int, int>> selectedWall) {
   auto cL = L;

   for(auto& [r, c]: selectedWall) {
      cL[r][c] = 1;
   }

   queue<pair<int, int>> q;

   for(auto p: V) {
      q.push(p);
   }

   while(!q.empty()) {
      int size = q.size();

      for(int i = 0; i < size; i++) {
         auto [r, c] = q.front(); q.pop();

         for(int i = 0; i < 4; i++) {
            pair<int, int> n = {r + RR[i], c + CC[i]};
            auto& [nr, nc] = n;

            if(nr >= 0 && nr < N &&
               nc >= 0 && nc < M &&
               cL[nr][nc] == 0
            ) {
               cL[nr][nc] = 2;
               q.push({nr, nc});
            }
         }
      }
   }

   

   int count = 0;

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
         if(cL[i][j] == 0) {
            ++count;
         }
      }
   }

   max = std::max(max, count);
}

void rec(int i, vector<pair<int, int>> selectedWall) {
   if(i >= B.size() || selectedWall.size() >= 3) {
      if(selectedWall.size() != 3) {
         return;
      }

      split(selectedWall);
      return;
   }
   rec(i + 1, selectedWall);
   selectedWall.push_back(B[i]);
   rec(i + 1, selectedWall);
}

void sol() {
   rec(0, vector<pair<int, int>>());
}

int main(void) {
   cin >> N >> M;
   int t;

   L.resize(N, vector<int>(M, 0));

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
         cin >> t;
         L[i][j] = t;
         if(t == 2) {
            V.push_back({i, j});
         }
         if(t == 0) {
            B.push_back({i, j});
         } 
      }
   }

   // for(int i = 0; i < N; i++) {
   //    for(int j = 0; j < M; j++) {
   //       cout << L[i][j];
   //    }
   //    cout << '\n';
   // }

   sol();

   cout << max;

   return 0;
}