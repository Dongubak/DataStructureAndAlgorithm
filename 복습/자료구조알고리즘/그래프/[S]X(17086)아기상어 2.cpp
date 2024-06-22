#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::queue;
using std::pair;

vector<vector<int>> w;
int n, m;
int r[8] = {1, 1, -1, -1, 1, -1, 0, 0};
int c[8] = {-1, 1, 1, -1, 0, 0, 1, -1};
int max = 0;


void searchSafe(int i, int j) {
   queue<pair<int, int>> q;
   vector<vector<int>> vis(n, vector<int>(m, 0));
   /// 여기는 초기에 한번 큐에 넣어주고 큐 조사하는걸로 바꿔야함
   vis[i][j] = 1;

   int dis = 0;
   for(int k = 0; k < 8; k++) {
      int nr = i + r[k], nc = j + c[k];
      if(nr >= 0 && nr < n && /// 유효한 좌표임
         nc >= 0 && nc < m && /// 유효한 좌표임
         // !w[nr][nc] && ///상어가 아님
         !vis[nr][nc] ///방문한 곳이 아님
      ) {
         if(w[nr][nc]) { /// 상어임
            max = std::max(max, 1);
            return;
         } else {
            vis[nr][nc] = 1;
            q.push({nr, nc});
         }
      }
   }
   dis++;
   

   while(!q.empty()) {
      int qsize = q.size();
      dis++;
      for(int i = 0; i < qsize; i++) {
         auto [pr, pc] = q.front(); q.pop(); /// queue에서 pop한 좌표
         for(int j = 0; j < 8; j++) {
            int nr = pr + r[j], nc = pc + c[j]; /// 주변 좌표
            if(nr >= 0 && nr < n && /// 유효한 좌표임
               nc >= 0 && nc < m && /// 유효한 좌표임
               // !w[nr][nc] && ///상어가 아님
               !vis[nr][nc] ///방문한 곳이 아님
            ) {
               vis[nr][nc] = 1;
               if(w[nr][nc]) { /// 상어임
                  max = std::max(max, dis);
                  return;
               } else {
                  q.push({nr, nc});
               }
            }
         }
      }
   }
}

void sol() {

   searchSafe(0, 0);
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         if(!w[i][j]) {
            searchSafe(i, j);
         }
      }
   }
}

int main(void) {
   cin.tie(NULL);
   std::ios_base::sync_with_stdio(false);

   int t;
   cin >> n >> m;
   w.resize(n);
   for(int i = 0; i < n; i++) {
      w[i].resize(m);
      for(int j = 0; j < m; j++) {
         cin >> w[i][j];
      }
   }


   sol();

   cout << max;
   // for(int i = 0; i < n; i++) {
   //    for(int j = 0; j < m; j++) {
   //       cout << w[i][j] << " ";
   //    }

   //    cout << '\n';
   // }

   return 0;
}

// 특정 칸에서 가장 가까운 아기상어와의 거리가 안전거리임

// 그러면 모든 칸에 대해서 안전거리를 구하면 될 듯

// 모든 칸 순회하고 그 칸에 상어가 있는 경우 패스
// 상어가 없는 경우 가장 가까운 상어를 탐색하여 안전거리를 구함

// 안전거리의 최댓값을 출력하면 됨

// 그러면 특정 칸에서 가장 가까운 상어까지의 거리를
// 구하는 것은 큐를 너비우선 탐색을 하면 될듯함

// 큐에서 꺼내자마자 큐 사이즈 만큼 큐에서 빼내면서 진행함
// 이때 대각선도 이동이 가능하므로 대각선도 포함함
