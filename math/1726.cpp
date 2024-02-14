#include <bits/stdc++.h>
using namespace std;

int mat[101][101];

struct pos {
public:
   int row;
   int col;
   int dir;
   pos(int r, int c, int d) : row(r), col(c), dir(d) {}
} posS, posD;

struct posQ {
public:
   int row;
   int col;
   int dir;
   int count;
   posQ(int r, int c, int d, int co) : row(r), col(c), dir(d), count(co) {}
};

void sol(int r, int c) {
   queue<posQ> q;
   q.push(posQ(posS.row, posS.col, posS.dir, 0));

   while(q.empty()) {
      posQ pp = q.front();
      q.pop();


   }

}

int main(void) {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   memset(mat, -1, sizeof(mat));
   int r, c, t;
   cin >> r >> c;
   
   for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
         cin >> t;
         mat[i][j] = t;
      }
   }

   int rr, cc, dd;
   cin >> rr >> cc >> dd;
   posS.row = rr;
   posS.col = cc;
   posS.dir = dd;

   cin >> rr >> cc >> dd;
   posD.row = rr;
   posD.col = cc;
   posD.dir = dd;

   sol(r, c);

   return 0;
}