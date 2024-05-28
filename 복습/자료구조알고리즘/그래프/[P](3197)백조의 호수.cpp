#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

struct pos {
   int row;
   int col;
   int day;

   pos(int r, int c, int d) : row(r), col(c), day(d) {}

};

bool findL(vector<vector<int>>& lake, vector<pair<int, int>>& Lpos) {
  int c = 0;
   vector<vector<int>> vis(lake.size(), vector<int>(lake[0].size(), 0));
   int lr, lc;
   lr = Lpos[0].first;
   lc = Lpos[0].second;

   queue<pos> q;
   q.push(pos(lr, lc, 0));
   vis[lr][lc] = 1;


   while(!q.empty()) {
      int lr = q.front().row;
      int lc = q.front().col;
      int day = q.front().day;

      q.pop();

      for(int i = 0; i < 4; i++) {
         int R = max(0, min(lr + y[i], int(lake.size()) - 1));
         int C = max(0, min(lc + x[i], int(lake[0].size()) - 1));

         if((lake[R][C] != -2 && lake[R][C] != -1) && !vis[R][C]) {
            vis[R][C] = 1;
            q.push(pos(R, C, max(lake[lr][lc], day)));
         } else if (R == Lpos[1].first && C == Lpos[1].second && !vis[R][C]) {
            cout << day;
            return true;
         }
      }
   }
}

int changeFromXtoDot(
      vector<vector<int>>& currentLake,
      int r, int c, int k) {
         int count = 0;
   for(int i = 0; i < 4; i++) {
      if(currentLake[max(0, min(r + y[i], int(currentLake.size()) - 1))][max(0, min(c + x[i], int(currentLake[0].size()) - 1))] == -2) {
          currentLake[r + y[i]][c + x[i]] = k;
          count += 1;
      }
   }

   return count;
}

void chdot(vector<vector<int>>& lake) {
   int r = lake.size();
   int c = lake[0].size();
    int k = 0;

   // while(!isValid(lake, k)) {
   //    for(int i = 0; i < r; i++) {
   //       for(int j = 0; j < c; j++) {
   //          cout << lake[i][j];
   //       }
   //       cout << '\n';
   //    }

   //    for(int i = 0; i < r; i++) {
   //       for(int j = 0; j < c; j++) {
   //          if(lake[i][j] == k) {
   //             changeFromXtoDot(lake, i, j, k + 1);
   //          }
   //       }
   //    }

   //    d++;
   //    k++;
   // }
   while(1) {
      int count = 0;
      for(int i = 0; i < r; i++) {
         for(int j = 0; j < c; j++) {
            if(lake[i][j] == k)
               count += changeFromXtoDot(lake, i, j, k + 1);
            
         }
      }
      if(count == 0) {
         for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
               cout << lake[i][j];
            }
            cout << '\n';
         }

         cout << '\n';
         return;
      }
      k = k + 1;
   }
}

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int r, c;
   cin >> r >> c;
   vector<vector<int>> lake(r, vector<int>(c, 0));
   vector<pair<int, int>> Lpos;

   char in;
   map<char, int> m;
   map<int, char> rm;
   m['.'] = 0; m['L'] = -1; m['X'] = -2;
   cin.get();
   for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
         cin >> in;
         lake[i][j] = m[in];

         if(in == 'L') {
            Lpos.push_back(make_pair(i, j));
         }
      }
   }

   chdot(lake);
   findL(lake, Lpos);



   return 0;
}