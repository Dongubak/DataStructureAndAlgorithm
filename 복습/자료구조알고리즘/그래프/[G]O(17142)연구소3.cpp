#include <iostream>
#include <vector>
#include <queue>

// 큐에 하나도 안 넣고 문제 찾고 있었음;
// 재귀함수 탈출조건에 return안넣고 왜 안 멈추나 하고 있었음

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::queue;

int N, M;

vector<vector<int>> L;
vector<pair<int, int>> V;

int min = 10e5;

int RR[] = {0, 0, 1, -1};
int CC[] = {1, -1, 0, 0};

bool isAllVirus(const vector<vector<int>>& L) {
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         if(L[i][j] == 0) {
            return false;
         }
      }
   }

   return true;
}

void cal(const vector<pair<int, int>>& selectedVirus) {
   if(isAllVirus(L)) {
      cout << 0;
      exit(0);
   }
   vector<vector<int>> cL = L;
   queue<pair<int, int>> q;

   for(auto& [r, c]: selectedVirus) {
      cL[r][c] = 3; /// 활성 바이러스화
      q.push({r, c});
   }

   int t = 0;
   while(!q.empty()) {
      ++t;

      int size = q.size();

      for(int i = 0; i < size; i++) {
         auto [r, c] = q.front(); q.pop();

         for(int j = 0; j < 4; j++) {
            int nr = r + RR[j], nc = c + CC[j];
            if(nr >= 0 && nr < N &&
               nc >= 0 && nc < N &&
            (cL[nr][nc] == 0 || cL[nr][nc] == 2)) {
               cL[nr][nc] = 3;
               q.push({nr, nc});
            }
         }
      }

      if(isAllVirus(cL)) {
         break;
      }
   }
   // for(int i = 0; i < N; i++) {
   //    for(int j = 0; j < N; j++) {
   //       cout << cL[i][j];
   //    }
   //    cout << '\n';
   // }
   // cout << t << '\n';
   // cout << '\n';

   if(isAllVirus(cL)) {
      min = std::min(min, t);
   }
}

void rec(int i, vector<pair<int, int>> selectedVirus) {
   if(selectedVirus.size() >= M || i >= V.size()) {
      if(selectedVirus.size() != M) {
         return;
      }
   
      cal(selectedVirus);
      return;
   }

   rec(i + 1, selectedVirus);

   selectedVirus.push_back(V[i]);
   rec(i + 1, selectedVirus);
}

void sol() {
   rec(0, vector<pair<int, int>>());

   if(min == 10e5) {
      cout << -1;
   } else {
      cout << min;
   }
}

int main(void) {
   cin >> N >> M;
   int t;
   L.resize(N, vector<int>(N, 0));

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         cin >> t;

         L[i][j] = t;
         if(t == 2) {
            V.push_back({i, j});
         }
      }
   }

   // for(auto [r, c] : V) {
   //    cout << "r : " << r << ", c : " << c << '\n';
   // }


   sol();

   return 0;
}