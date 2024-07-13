#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

const int MAXN = 100000;
vector<int> tree(4 * MAXN);
int n;

void build(const vector<int>& data, int i, int s, int e) {
   if(s == e) {
      tree[i] = data[s];
   } else {
      int m = (s + e) / 2; /// s와 e의 중간인덱스
      
      build(data, 2 * i + 1, s, m);
      build(data, 2 * i + 2, m + 1, e);
      
      tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
   }
}

int query(int i, int s, int e, int qs, int qe) {
   if(e < qs || s > qe) {
      return INT_MAX;
   }

   if(qs <= s && e <= qe) {
      return tree[i];
   }

   int m = (s + e) / 2;

   return min(query(2 * i + 1, s, m, qs, qe), query(2 * i + 2, m + 1, e, qs, qe));
}

void update(int i, int s, int e, int idx, int v) {
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
      tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   // 데이터 입력
   vector<int> data = {1, 3, 2, 7, 9, 11};
   n = data.size();
   
   // 세그먼트 트리 생성
   build(data, 0, 0, n - 1);

   // 구간 최솟값 쿼리
   cout << "Minimum value in range [1, 4]: " << query(0, 0, n - 1, 1, 4) << endl; // 2

   update(0, 0, n - 1, 3, 0);
   cout << "Minimum value in range [1, 4] after update: " << query(0, 0, n - 1, 1, 4) << endl; // 0

   return 0;
}