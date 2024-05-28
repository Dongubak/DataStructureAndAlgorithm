#include <iostream>
#include <cstring>

using namespace std;

class pos {
public:
   pair<int, int> row;
   pair<int, int> col;

   pos(int rp, int rq,
      int cp, int cq
   ) {
      row = make_pair(rp, rq);
      col = make_pair(cp, cq);
   }
};

char a[2187 + 1][2187 + 1];

///[p, q) 범위
void rec(pos po) {

   int brp = po.row.first + (po.row.second - po.row.first + 1) / 3;
   int brq = po.row.first + (po.row.second - po.row.first + 1) * 2 / 3;
   int bcp = po.col.first + (po.col.second - po.col.first + 1) / 3;
   int bcq = po.col.first + (po.col.second - po.col.first + 1) * 2 / 3;

   if(po.row.first >= po.row.second - 1 ||
      po.col.first >= po.col.second - 1
   ) {
      return;
   }

   for(int i = brp; i < brq; i++) {
      for(int j = bcp; j < bcq; j++) {
         ::a[i][j] = 0;
      }
   }

   rec(pos(po.row.first, brp, po.col.first, bcp));
   rec(pos(brp, brq, po.col.first, bcp));
   rec(pos(brq, po.row.second, po.col.first, bcp));

   rec(pos(po.row.first, brp, bcp, bcq));
   rec(pos(brq, po.row.second, bcp, bcq));

   rec(pos(po.row.first, brp, bcq, po.col.second));
   rec(pos(brp, brq, bcq, po.col.second));
   rec(pos(brq, po.row.second, bcq, po.col.second));


}

void sol(int n) {
   rec(pos(1, n, 1, n));
}

int main(void) {
   memset(a, 1, sizeof(a));

   int n;
   cin >> n;

   sol(n + 1);
   
   for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
         if(a[i][j] == 1) {
            cout << "*";
         } else {
            cout << " ";
         }
      }
      cout << '\n';
   }


   return 0;
}