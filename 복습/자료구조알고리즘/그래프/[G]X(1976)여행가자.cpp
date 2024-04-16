#include <iostream>
#include <vector>

using namespace std;

// edge가 direct인 경우에 대해서 disjointset을 통해 한쪽으로만 이동가능하며
// 다른 쪽으로 이동 불가능하다는 것을 확인한다.
// 이떄 founder와 child끼리의 사이클이 발생할 수 있음 이를 해결해야함


// Edge가 direct인 경우와 undirect인 경우에 대해서 파악해야함

int g[200 + 1][200 + 1];
int mvis[1000];

class DisjointSet {
public:
   vector<int> founder;

   DisjointSet(int n) {
      founder.resize(n + 1);
   }

   int find(int p) {
      if(p == founder[p]) {
         return p;
      }

      return founder[p] = find(founder[p]);
   }

   bool merge(int p1, int p2) {
      int f1 = find(p1);
      int f2 = find(p2);

      if(f1 != f2) {
         founder[f1] = f2;
         return true;
      } else {
         return false;
      }
   }
};

int main(void) {
   int n, m;
   ///n: 도시수
   ///m: 방문해야할 도시수
   cin >> n >> m;

   for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
         g[i][j] = 1;
      }
   }

   for(int i = 0; i < m; i++) {
      cin >> mvis[i];
   }



}