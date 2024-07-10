#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int R, C, N;
/// N은 상어의 마리 수

class ob {
   public:
   int r;
   int c;
   int s;
   int d;
   int z;
   ob(int R = 0, int C = 0, int S = 0, int D = 0, int Z = 0) : r(R), c(C), s(S), d(D), z(Z){}
};

int RR[4] = {-1, 1, 0, 0};
int CC[4] = {0, 0, 1, -1};

void searchAndKill(vector<vector<int>>& s1, int currentHumanColumn, int& sum) {
   for(int j = 0; j < R; j++) {
      if(!s1[j][currentHumanColumn]) {
         sum += s1[j][currentHumanColumn];
         s1[j][currentHumanColumn] = 0;
         break;
      }
   }
}

void sol(vector<vector<int>>& s1, vector<ob>& shark) {
   int sum = 0;
   for(int i = 0; i < C; i++) {
      int currentHumanColumn = i;
      searchAndKill(s1, currentHumanColumn, sum);

      vector<vector<int>> newS = vector<vector<int>>(R, vector<int>(C, 0));

      for(auto& sh: shark) {
         auto& [r, c, s, d, z] = sh;

         if(s1[r][c] != z || z == 0) {
            z = 0;
            continue;
         }

         int n = s;
         while(n != 0) {
            if(!(r + RR[d] >= 0 && r + RR[d] < R)) {
               d = d == 3 ? 4 : 3;
            }

            if(!(c + CC[d] >= 0 && c + CC[d] < C)) {
               d = d == 2 ? 1 : 2;
            }
            r = r + RR[d]; 
            c = c + CC[d];
            n = n - 1;
         }

         if(newS[r][c] < z) { /// 교체
            newS[r][c] = z;
         } else { /// 고대로
            z = 0;
         }
      }

      s1 = newS;
   }

   cout << sum;
}

int main(void) {
   cin >> R >> C >> N;
   

   int r, c, s, d, z;
   vector<vector<int>> s1(R, vector<int>(C, 0));
   vector<ob> shark;

   for(int i = 0; i < N; i++) {
      cin >> r >> c >> s >> d >> z;
      s1[r][c] = z;
      shark.push_back(ob(r, c, s, d, z));
   }

   sol(s1, shark);

   return 0;
}