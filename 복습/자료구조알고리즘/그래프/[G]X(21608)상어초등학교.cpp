#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::cin;
using std::vector;
using std::pair;
using std::priority_queue;

int N;

vector<vector<int>> F;
vector<vector<int>> R;

int RR[4] = {0, 0, 1, -1};
int CC[4] = {1, -1, 0, 0};

class Ob {
public:
   int nf; // n of favorite friend
   int nb; // n of blank
   pair<int, int> p; //pos
   Ob(int f, int b, pair<int, int> P) : nf(f), nb(b), p(P) {}

   bool operator>(const Ob& other) const {
      if(nf > other.nf) {
         return true;
      } else if(nf == other.nf) {
         if(nb > other.nb) {
            return true;
         } else if(nb == other. nb) {
            // if(p.first < other.p.first) {
            //    return true;
            // } else if (p.first == other.p.first) {
            //    if(p.second < other.p.second) {
            //       return true;
            //    } else {
            //       return false;
            //    }
            // } else {
            //    return false;
            // }
            if(p < other.p) {
               return true;
            } else {
               return false;
            }
         } else {
            return false;
         }
      } else {
         return false;
      }
   }

   bool operator<(const Ob& other) const {
      return !(*this > other);
   }
};

void sol() {
   priority_queue<Ob, vector<Ob>, std::less<Ob>> pq;

   for(auto p: F) {
      auto ptr = p.begin();
      int c = *(ptr++);
      // cout << "c : " << c;

      for(int i = 0; i < N; i++) {
         for(int j = 0; j < N; j++) {

            int nf = 0;
            int nb = 0;

            if(R[i][j] == -1) {
               for(int k = 0; k < 4; k++) {
                  pair<int, int> np = {i + RR[k], j + CC[k]};
                  auto& [nr, nc] = np;

                  if(!(nr >= 0 && nr < N &&
                     nc >= 0 && nc < N
                     )
                  ) {
                     continue;
                  }

                  for(auto pt = ptr; pt != p.end(); pt++) {
                     if(R[nr][nc] == *pt) {
                        ++nf;
                     }
                  }

                  if(R[nr][nc] == -1) {
                     nb++;
                  }
               }

               pq.push(Ob(nf, nb, {i, j}));
            }
            
         }
      }

      auto [z1, z2, p1] = pq.top();
      auto [cr, cc] = p1;
      R[cr][cc] = c;

      // cout << z1 << " " << z2 << " " << cr << " " << cc << '\n';

      // for(int i = 0; i < N; i++) {
      //    for(int j = 0; j < N; j++) {
      //       cout << R[i][j] << " ";
      //    }
      //    cout << '\n';
      // }
      // if(c == 0) {
      //    priority_queue<Ob> cpq = pq;
      //    while(!cpq.empty()) {
      //       cout << cpq.top().p.first << " " << cpq.top().p.second << ", ";
      //       cpq.pop();
      //    }

      //    cout << '\n';
      // }

      // cout << '\n';


      pq = priority_queue<Ob>();

   }
}

int main(void) {
   cin >> N;

   F.resize(N * N, vector<int>(5, 0));
   R.resize(N, vector<int>(N, -1));

   int t;
   for(int i = 0; i < N * N; i++) {
      for(int j = 0; j < 5; j++) {
         cin >> t;
         F[i][j] = t - 1;
      }
   }

   sol();

   int l = 0;

   // for(int i = 0; i < N; i++) {
   //    for(int j = 0; j < N; j++) {
   //       cout << R[i][j] << " ";
   //    }
   //    cout << '\n';
   // }

   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         int s = R[i][j]; // 현재 학생 번호
         int ll = 0; // local L;
         for(int k = 0; k < 4; k++) {
            pair<int, int> np = {i + RR[k], j + CC[k]}; // 상하 좌우
            auto [nr, nc] = np;

            if(!(nr >= 0 && nr < N &&
               nc >= 0 && nc < N)
            ) {
               continue;
            } // 유효한 좌표 아님

            vector<int> fs; /// 현재 학생의 좋아하는 친구들
            for(auto f: F) {
               if(f[0] == s) {
                  fs = f;
                  break;
               }
            }

            for(auto os: fs) { /// 좋아하는 친구
               if(R[nr][nc] == os) {
                  ++ll;
               }
            }
         }


         if(ll == 2) {
            l += 10;
         } else if(ll == 3) {
            l += 100;
         } else if(ll == 4) {
            l += 1000;
         } else {
            l += ll;
         }
      }
   }

   cout << l;

   return 0;
}