#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N;

int r[4] = {1, -1, 0,  0};
int c[4] = {0,  0, 1, -1};

class FindState {
public:
   int moveCount;
   int row;
   int col;

   FindState(int MOVECOUNT, int ROW, int COL) : moveCount(MOVECOUNT), row(ROW), col(COL) {}

   bool operator<(const FindState other) const {
      if(moveCount != other.moveCount) {
         return moveCount > other.moveCount;
      }
      if(row != other.row) {
         return row > other.row;
      }
      return col > other.col;
   }
};

class MoveState {
public:
   int size;
   int moveCount;
   int rest;
   int row;
   int col;

   MoveState(int SIZE, int MOVECOUNT, int REST, int R, int C) : size(SIZE), moveCount(MOVECOUNT), rest(REST), row(R), col(C) {}
};

FindState findEqualOrSmall(MoveState cur, vector<vector<int>>& b) {
   priority_queue<FindState> edible;
   queue<pair<int, int>> q;
   vector<vector<bool>> vis(N, vector<bool>(N, false));
   q.push({cur.row, cur.col});
   vis[cur.row][cur.col] = true;

   int moveCount = 0;
   while(!q.empty()) {
      int qsize = q.size();
      for(int i = 0; i < qsize; i++) {
         auto [shotRow, shotCol] = q.front(); q.pop();
         
         for(int j = 0; j < 4; j++) {

            int destRow = shotRow + r[j], destCol = shotCol + c[j];

            if(destRow >= 0 && destRow < N
             && destCol >= 0 && destCol < N 
             && !vis[destRow][destCol]) {

               vis[destRow][destCol] = true;

               if(b[destRow][destCol] == 0 || b[destRow][destCol] == cur.size) {
                  q.push({destRow, destCol});

               } else if(b[destRow][destCol] < cur.size) {
                  edible.push(FindState(moveCount + 1, destRow, destCol));

               }

            }
         }
      }
      moveCount++;
   }

   if(edible.empty()) {
      return FindState(-1, 0, 0);
   } else {
      return edible.top();
   }
}

void sol(vector<vector<int>>& b, pair<int, int>& babySharkInitPos) {
   MoveState cur(2, 0, 2, babySharkInitPos.first, babySharkInitPos.second);

   while (true) {
      FindState edible = findEqualOrSmall(cur, b);
      if(edible.moveCount == -1) {
         break;
      }

      cur.row = edible.row;
      cur.col = edible.col;
      cur.moveCount += edible.moveCount;
      cur.rest -= 1;
      if(cur.rest == 0) {
         cur.size += 1;
         cur.rest = cur.size;
      }
      b[edible.row][edible.col] = 0;
   }

   cout << cur.moveCount;
}

int main(void) {
   int t;
   cin >> N;

   vector<vector<int>> b(N, vector<int>(N, 0));
   pair<int, int> babySharkInitPos;
   for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         cin >> t;

         if(t == 9) {
            babySharkInitPos = {i, j};
            b[i][j] = 0;
         } else {
            b[i][j] = t;
         }
      }
   }

   sol(b, babySharkInitPos);

   return 0;
}
