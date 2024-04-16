#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

class Node {
public:
   int time;
   int number;

   Node(int t, int n) : time(t), number(n) {}

   bool operator>(const Node& other) const {
      return time > other.time;
   }
};

void sol(int st, int end) {
   vector<int> sht(100000 + 1, numeric_limits<int>::max()); // end + 2 대신 end + 1 사용
   priority_queue<Node, vector<Node>, greater<Node>> pq;
   sht[st] = 0;
   pq.emplace(Node(0, st));

   while(!pq.empty()) {
      int cur = pq.top().number;
      int time = pq.top().time;
      pq.pop(); 

      // 2 * cur 연산
      if(cur * 2 <= 100000 + 1 && sht[cur] < sht[2 * cur]) {
         sht[2 * cur] = sht[cur];
         pq.emplace(Node(sht[2 * cur], 2 * cur));
      }

      // cur + 1 연산
      if(cur + 1 <= 100000 + 1 && sht[cur] + 1 < sht[cur + 1]) {
         sht[cur + 1] = sht[cur] + 1;
         pq.emplace(Node(sht[cur + 1], cur + 1));
      }

      // cur - 1 연산, cur이 0보다 클 때만 수행
      if(cur > 0 && sht[cur] + 1 < sht[cur - 1]) {
         sht[cur - 1] = sht[cur] + 1;
         pq.emplace(Node(sht[cur - 1], cur - 1));
      }
   }

   cout << sht[end];
}

int main() {
   int st, en;
   cin >> st >> en;

   sol(st, en);

   return 0;
}
