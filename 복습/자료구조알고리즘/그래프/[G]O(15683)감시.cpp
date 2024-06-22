#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::tuple;

class ob {
public:
   int r;
   int c;
   int t;
   int d;

   ob(int R, int C, int T, int D) : r(R), c(C), t(T), d(D){}
};
int min = 10e5;
vector<vector<int>> map;
vector<tuple<int, int, int>> cctv;
int r, c;
int k;
int d[] = {4, 2, 4, 4, 1};

int r1[] = {-1, 0, 1, 0};
int c1[] = {0, 1, 0, -1};

int d2[2][2] = {{0, 2}, {1, 3}};
int d3[4][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
int d4[4][3] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}};
int d5[2][4] = {{0, 1, 2, 3}};

void getMin(vector<ob>& selected) {
   vector<vector<int>> cmap = map;

   for(auto o: selected) {
      auto [r, c, t, d] = o;

      if(t == 1) {
         pair<int, int> md = {r1[d], c1[d]};
         int cr = r, cc = c;

         while(cr >= 0 && cr < ::r &&
               cc >= 0 && cc < ::c) {
                  if(cmap[cr][cc] == 6) {
                     break;
                  }

                  if(cmap[cr][cc] == 0) {
                     cmap[cr][cc] = -1;
                  }

                  cr += md.first;
                  cc += md.second;
            }
      } else if(t == 2) {
         for(int i = 0; i < 2; i++) {
            pair<int, int> md = {r1[d2[d][i]], c1[d2[d][i]]};
            // pair<int, int> md1 = {r1[d2[d][0]], c1[d2[d][0]]};
            // pair<int, int> md2 = {r1[d2[d][1]], c1[d2[d][1]]};
            int cr = r, cc = c;

            while(cr >= 0 && cr < ::r &&
                  cc >= 0 && cc < ::c) {
                     if(cmap[cr][cc] == 6) {
                        break;
                     }

                     if(cmap[cr][cc] == 0) {
                        cmap[cr][cc] = -1;
                     }

                     cr += md.first;
                     cc += md.second;
               }
         }
         
      } else if(t == 3) {
         for(int i = 0; i < 2; i++) {
            pair<int, int> md = {r1[d3[d][i]], c1[d3[d][i]]};
            // pair<int, int> md1 = {r1[d2[d][0]], c1[d2[d][0]]};
            // pair<int, int> md2 = {r1[d2[d][1]], c1[d2[d][1]]};
            int cr = r, cc = c;

            while(cr >= 0 && cr < ::r &&
                  cc >= 0 && cc < ::c) {
                     if(cmap[cr][cc] == 6) {
                        break;
                     }

                     if(cmap[cr][cc] == 0) {
                        cmap[cr][cc] = -1;
                     }

                     cr += md.first;
                     cc += md.second;
               }
         }
      } else if(t == 4) {
         for(int i = 0; i < 3; i++) {
            pair<int, int> md = {r1[d4[d][i]], c1[d4[d][i]]};
            // pair<int, int> md1 = {r1[d2[d][0]], c1[d2[d][0]]};
            // pair<int, int> md2 = {r1[d2[d][1]], c1[d2[d][1]]};
            int cr = r, cc = c;

            while(cr >= 0 && cr < ::r &&
                  cc >= 0 && cc < ::c) {
                     if(cmap[cr][cc] == 6) {
                        break;
                     }

                     if(cmap[cr][cc] == 0) {
                        cmap[cr][cc] = -1;
                     }

                     cr += md.first;
                     cc += md.second;
               }
         }
      } else { /// t = 5
         for(int i = 0; i < 4; i++) {
         pair<int, int> md = {r1[d5[d][i]], c1[d5[d][i]]};
         // pair<int, int> md1 = {r1[d2[d][0]], c1[d2[d][0]]};
         // pair<int, int> md2 = {r1[d2[d][1]], c1[d2[d][1]]};
         int cr = r, cc = c;

         while(cr >= 0 && cr < ::r &&
               cc >= 0 && cc < ::c) {
                  if(cmap[cr][cc] == 6) {
                     break;
                  }

                  if(cmap[cr][cc] == 0) {
                     cmap[cr][cc] = -1;
                  }

                  cr += md.first;
                  cc += md.second;
            }
         }
      }
   }
   int sum = 0;
   // cout << " ----- " << '\n';
   for(int i = 0; i < ::r; i++) {
      for(int j = 0; j < ::c; j++) {
         if(cmap[i][j] == 0) {
            ++sum;
         }
         // cout << cmap[i][j] << " ";
      }
      // cout << '\n';
   }
   // cout << " ----- " << '\n';

   min = std::min(sum, min);
}

void rec(int i, vector<ob> selected) {
  ///i: cctv인덱스, selected: 선택된 cctv
  
  if(i == cctv.size()) {

      getMin(selected);
      return;
  }

   auto [r, c, t] = cctv[i];
   for(int j = 0; j < d[t - 1]; j++) {
      selected.push_back({r, c, t, j});
      rec(i + 1, selected);
      selected.pop_back();
   }
}

void sol() {
   rec(0, vector<ob>());
}

int main(void) {
   int t;
   cin >> r >> c;

   map.resize(r, vector<int>(c));


   for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
         cin >> t;
         map[i][j] = t;

         if(t > 0 && t < 6) {
            cctv.push_back({i, j, t});
         }
      }
   }


   sol();
   cout << min << '\n';

   return 0;
}

