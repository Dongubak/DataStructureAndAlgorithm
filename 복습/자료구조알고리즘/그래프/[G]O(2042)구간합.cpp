#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int N, M, K;

using std::cin;
using std::cout;
using std::vector;

long long A[1000000 + 1];
long long tree[20000001];

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

void build(long long *data, int i, int s, int e) {
   if(s == e) {
      tree[i] = data[s];
   } else {
      int m = (s + e) / 2; /// s와 e의 중간인덱스
      
      build(data, 2 * i + 1, s, m);
      build(data, 2 * i + 2, m + 1, e);
      
      tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
   }
}

long long query(int i, int s, int e, int qs, int qe) {
   if(e < qs || s > qe) {
      return 0;
   }

   if(qs <= s && e <= qe) {
      return tree[i];
   }

   int m = (s + e) / 2;

   return query(2 * i + 1, s, m, qs, qe) + query(2 * i + 2, m + 1, e, qs, qe);
}

void update(int i, int s, int e, int idx, long long v) {
   if (s == e) {
      // 리프 노드
      tree[i] = v;
   } else {
      int mid = (s + e) / 2;
      if (idx <= mid) {
         update(2 * i + 1, s, mid, idx, v);
      } else {
         update(2 * i + 2, mid + 1, e, idx, v);
      }
      tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
   }
}

int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   N = readInt();
   M = readInt();
   K = readInt();
   // cin >> N >> M >> K;
   for(int i = 0; i < N; i++) {
      A[i] = readLong();
   }

   build(A, 0, 0, N - 1);

   int t, i;
   long long v;
   for(int j = 0; j < M + K; j++) {
      t = readInt();
      i = readInt();
      v = readLong();
      // cin >> t >> i >> v;
      if(t == 1) { /// change
         update(0, 0, N - 1, i - 1, v);
      } else { /// get sum
         cout << query(0, 0, N - 1, i - 1, v - 1) << '\n';
      }
   }

   return 0;
}