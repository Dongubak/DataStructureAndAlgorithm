#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::pair;

int map[101][101];

class State {
public:
   pair<int, int> prev;
   pair<int ,int> next;
   int d;

   State(pair<int, int> P, pair<int, int> N, int D) : prev(P), next(N), d(D){}
};

void sol(int x, int y, int d, int g) {
   vector<State> his;
   if(g == 0) {
      map[y][x] = 1;
      if(d == 0) {
         map[y][x + 1] = 1;
      } else if(d == 1) {
         map[y - 1][x] = 1;
      } else if(d == 2) {
         map[y][x - 1] = 1;
      } else {
         map[y + 1][x] = 1;
      }
      return;
   }


   if(d == 0) {
      his.push_back(State({x, y}, {x + 1, y}, 0));
   } else if(d == 1) {
      his.push_back(State({x, y}, {x, y - 1}, 1));
   } else if(d == 2) {
      his.push_back(State({x, y}, {x - 1, y}, 2));
   } else {
      his.push_back(State({x, y}, {x, y + 1}, 3));
   }

   for(int i = 0; i < g; i++) { ///g번
   ///g = 1인 경우 1번 실행
      for(int j = pow(2, i) - 1; j >= 0; j--) {
         State move = his.back();
         move.prev = move.next;

         if(his[j].d + 1 == 1) {
            move.next.second = move.prev.second - 1;
            move.d = 1;
         }
         else if(his[j].d + 1 == 2) {
            move.next.first = move.prev.first - 1;
            move.d = 2;
         } else if(his[j].d + 1 == 3) {
            move.next.second = move.prev.second + 1;
            move.d = 3;
         } else  {//(his[j].d == 4)
            move.next.first = move.prev.first + 1;
            move.d = 0;
         }
         his.push_back(move);
      }
   }

   map[his[0].prev.second][his[0].prev.first] = 1;
   for(auto st: his) {
      map[st.next.second][st.next.first] = 1;
   }
}

int main(void) {
   int x, y, d, g, n;
   cin >> n;

   for(int i = 0; i < n; i++) {
      cin >> x >> y >> d >> g;
      sol(x, y, d, g);
   }

   int c = 0;
   for(int i = 0; i < 100; i++) {
      for(int j = 0; j < 100; j++) {
         if(map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
            c++;
         }
      }
   }

   cout << c;

   return 0;
}