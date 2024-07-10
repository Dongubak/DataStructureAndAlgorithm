#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using std::queue;
using std::pair;

int N, M, K;

class FB {
public:
   int r;
   int c;
   int m;
   int s;
   vector<int> d;

   FB(int R = 0, int C = 0, int M = 0, int S = 0, int D = 0) :
   r(R), c(C), m(M), s(S) {
      d.push_back(D);
   }
};

int RR[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int CC[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<vector<FB>> S;
vector<FB> F;

void fireBallMove() {
   queue<FB> q;
   for(const auto& f: F) {
      q.push(f);
   }

   while(!q.empty()) {
      int size = q.size();

      vector<vector<FB>> nS(N, vector<FB>(N, FB()));

      for(int i = 0; i < size; i++) {
         auto [r, c, m, s, d] = q.front(); q.pop();
         int e = s % N;
         for(auto ed: d) {
            pair<int, int> p = {r, c};
            auto& [nr, nc] = p;

            for(int j = 0; j < e; j++) {
               nr = r + RR[ed];
               nc = c + CC[ed];
               
               if(nr < 0) nr = N - 1;
               else if(nr > N) nr = 0;
               

               if(nc < 0) nc = N - 1;
               else if(nc > N) nc = 0;
            }

            nS[nr][nc].m += m;
            nS[nr][nc].s += s;
            nS[nr][nc].d.push_back(ed);
            nS[nr][nc].r = nr, nS[nr][nc].c = nc;
            q.push(nS[nr][nc]);
         }
      }

      for(int i = 0; i < N; i++) {
         for(int j = 0; j < N; j++) {
            auto& [r, c, m, s, d] = nS[i][j];
            if(d.size() > 1) {
               m = m / 5;
               if(m == 0) {
                  continue;
               }
               s = s / d.size();

               bool allEven = true, allOdd = true;

               for(auto k: d) {
                  if(k % 2 == 0) {
                     allOdd = 0;
                  }
                  if(k % 2 == 1) {
                     allEven = 0;
                  }

                  if(allOdd || allEven) {
                     nS[i][j].d = {0, 2, 4, 6};
                  } else {
                     nS[i][j].d = {1, 3, 5, 7};
                  }
               }
            }
         }
      }
      S = nS;
   }
}

void sol() {
   for(int i = 0; i < K; i++) {
      fireBallMove();
   }

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         if()
      }
   }
}

int main(void) {
   cin >> N >> M >> K;
   S.resize(N, vector<FB>(N, FB()));
   int r, c, m, s, d;
   for(int i = 0; i < M; i++) {
      cin >> r >> c >> m >> s >> d;
      F.push_back({r, c, m, s, d});
   }

   sol();

   return 0;
}