#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::queue;
using std::pair;

vector<vector<int>> A;

int RR[4] = {1, -1, 0, 0};
int CC[4] = {0, 0, 1, -1};

#define WBUF_SIZE (1 << 20)

char rbuf[WBUF_SIZE];
int ridx, nidx;

inline char read() {
	if (ridx == nidx) {
		nidx = fread(rbuf, 1, 1 << 20, stdin);
		if (!nidx) return 0;
		ridx = 0;
	}
	return rbuf[ridx++];
}
inline int readInt() {
	int sum = 0;
	char now = read();
	bool flg = false;

	while (now <= 32) now = read();
	if (now == '-') flg = true, now = read();
	while (now >= 48) sum = sum * 10 + now - '0', now = read();

	return flg ? -sum : sum;
}

inline long long readLong() {
	long long sum = 0;
	char now = read();
	bool flg = false;

	while (now <= 32) now = read();
	if (now == '-') flg = true, now = read();
	while (now >= 48) sum = sum * 10 + now - '0', now = read();

	return flg ? -sum : sum;
}

int main(void) {
   int N, M;
   N = readInt();
   M = readInt();
   // cin >> N >> M;

   A.resize(N, vector<int>(M, 0));

   pair<int, int> s;
   auto& [sr, sc] = s;
   int t;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         t = readInt();
         if (t == 2) {
               sr = i, sc = j;
               A[i][j] = 0; // 시작점은 거리 0으로 초기화
         } else if (t == 0) {
               A[i][j] = -2; // 갈 수 없는 땅은 -2로 설정
         } else {
               A[i][j] = -1; // 갈 수 있는 땅은 -1로 설정
         }
      }
   }

   queue<pair<int, int>> q;
   q.push({sr, sc});

   while (!q.empty()) {
      auto [cr, cc] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
         int nr = cr + RR[i], nc = cc + CC[i];
         if (nr >= 0 && nr < N && nc >= 0 && nc < M && A[nr][nc] == -1) {
               A[nr][nc] = A[cr][cc] + 1;
               q.push({nr, nc});
         }
      }
   }

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         if (A[i][j] == -2) {
               cout << 0 << " ";
         } else if (A[i][j] == -1) {
               cout << -1 << " ";
         } else {
               cout << A[i][j] << " ";
         }
      }
      cout << '\n';
   }
    return 0;
}
