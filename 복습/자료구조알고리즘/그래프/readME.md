# 알고리즘 최적화

## 다익스트 알고리즘 최적화
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Edge {
public:
   int dst;
   int weight;

   Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   vector<vector<Edge>> g;
   int size;

   Graph(int s) : size(s + 1) {
      g.resize(s + 1);
   }

   void addEdge(int src, int dst, int weight) {
      g[src].emplace_back(Edge(dst, weight));
   }
};
///내부적으로 더하기 1을 했기 때문에 그냥 1시작 정점으로 생각하면 된다.

class Node {
public:
   int vertex; ///수정된 정점
   int weight; ///수정된 최단거리 값


   Node(int v, int w) : vertex(v), weight(w) {}

   bool operator>(const Node& other) const {
      return weight > other.weight;
   }
};

void getPriorityQueueState(priority_queue<Node, vector<Node>, greater<Node>> pq) {
   cout << "current pq state" << '\n';
   while(!pq.empty()) {
      cout << "vertex : " << pq.top().vertex << ", ";
      cout << "weight : " << pq.top().weight << '\n';

      pq.pop();
   }
}

void dijstra(Graph& g, int st) {
   vector<int> sht(g.size, numeric_limits<int>::max());
   sht[st] = 0;

   priority_queue<Node, vector<Node>, greater<Node>> pq;
   pq.push(Node(st, 0));

   while(!pq.empty()) {
      
      int cur = pq.top().vertex;
      int we = pq.top().weight;

      if(we != sht[cur]) {
         continue;
      } ///꺼낸 정점의 최단거리 값과 최단거리표의 정점의 값이 다른 경우


      getPriorityQueueState(pq);
      pq.pop();

      for(const auto& edge: g.g[cur]) {
         if(sht[cur] + edge.weight < sht[edge.dst]) {
            sht[edge.dst] = sht[cur] + edge.weight;
            pq.emplace(Node(edge.dst, sht[edge.dst]));
         }
      }
   }

   for(int i = 1; i < g.size; i++) {
      if(sht[i] == numeric_limits<int>::max()) {
         cout << "INF" << '\n';
      } else {
         cout << sht[i] << '\n';
      }
   }
}

int main(void) {
   int vn, en, st;
   cin >> vn >> en >> st;
   Graph g(vn);

   int s, d, w;

   for(int i = 0; i < en; i++) {
      cin >> s >> d >> w;

      g.addEdge(s, d, w);
      g.addEdge(d, s, w);
   }

   dijstra(g, st);

   return 0;
}
```

Dijkstra 알고리즘을 사용하는 코드에서 특정 부분이 최적화를 돕는 방법에 대해 질문해주셨습니다. 여기서 `if(we != sht[cur]) { continue; }` 구문은 Dijkstra 알고리즘의 중요한 최적화 기법 중 하나를 구현하고 있습니다.

이 최적화는 **"잘못된 또는 오래된 우선순위 큐 항목의 건너뛰기(skip)"** 라고 할 수 있습니다. 이 부분이 왜 필요한지 설명드리겠습니다:

### 우선순위 큐와 최단 경로 업데이트
Dijkstra 알고리즘에서는 각 정점까지의 최단 경로를 추정하면서 이 추정값을 우선순위 큐에 저장합니다. 각 정점에 대해 더 짧은 경로를 발견할 때마다 이 경로를 우선순위 큐에 추가합니다. 따라서, 우선순위 큐에는 같은 정점에 대한 여러 개의 다른 경로 가중치가 존재할 수 있습니다.

### 최적화의 필요성
우선순위 큐에서 가장 작은 가중치를 가진 정점을 꺼냈을 때, 해당 정점에 저장된 가중치(`we`)가 현재 정점까지의 알려진 최단 경로(`sht[cur]`)와 다를 수 있습니다. 이는 다음 두 가지 상황에서 발생할 수 있습니다:

1. **다른 경로를 통해 더 짧은 최단 경로를 이미 찾았다면:** 이 경우, 우선순위 큐에 있는 현재 항목은 더 이상 유효하지 않은 경로를 나타냅니다. 이전에 큐에 추가된 항목은 더 긴 경로를 가리키기 때문에, 우리가 이미 발견한 더 짧은 경로에 비해 불필요합니다.

2. **경로가 더 이상 최적이 아닌 경우:** 다른 정점을 통해 더 짧은 경로를 발견하면, 우선순위 큐의 해당 정점 항목은 더 이상 최적의 경로를 제공하지 않습니다.

### 결과적인 이점
이 최적화를 통해 알고리즘은 이미 처리된 더 긴 경로의 정점을 재처리하는 것을 방지하여, 시간 복잡도를 개선합니다. 불필요한 정점의 확장을 방지함으로써, Dijkstra 알고리즘이 더 빠르게 실행될 수 있도록 합니다.

이 최적화는 특히 큰 그래프나 밀집 그래프에서 두드러진 성능 향상을 보여주는데, 이러한 그래프들은 같은 정점에 대해 많은 업데이트가 발생하기 때문입니다.


## 벨만포드 알고리즘 최적화

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>

using namespace std;

class Edge {
public:
   int dst;
   int weight;

   Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   vector<list<Edge>> g;
   int size;

   Graph(int s) : size(s + 1) {
      g.resize(s + 1);
   }

   void addEdge(int src, int dst, int weight) {
      g[src].emplace_back(Edge(dst, weight));
   }
};

class Node {
public:
   int vertex;
   int sht;

   Node(int v, int s) : vertex(v), sht(s) {}

   bool operator>(const Node& other) const {
      return sht > other.sht;
   }
};

void bellmanford(Graph& g, int st) {
   vector<long> sht(g.size, numeric_limits<long>::max());
   sht[st] = 0;
   
   bool isUpdated;

   // g.size -> v + 1
   for(int i = 0; i < g.size - 2; i++) {
      isUpdated = false;
      for(int j = 1; j < g.size; j++) {
         if(sht[j] == numeric_limits<long>::max()) {
            continue;
         }
         for(const auto& edge: g.g[j]) {
            if(sht[j] + edge.weight < sht[edge.dst]) {
               sht[edge.dst] = sht[j] + edge.weight;
               isUpdated = true;
            }
         }
      }

      if(!isUpdated) {
         break;
      }
   } 

   for(int i = 1; i < g.size; i++) {
      if(sht[i] == numeric_limits<long>::max()) {
         continue;
      }

      for(const auto& edge: g.g[i]) {
         if(sht[i] + edge.weight < sht[edge.dst]) {
            cout << -1;
            return;
         }
      }
   }
   

   for(int i = 2; i < g.size; i++) {
      if(sht[i] == numeric_limits<long>::max()) {
         cout << -1 << '\n';
      } else {
         cout << sht[i] << '\n';
      }
   }
}

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);
   int vn, en, st;
   cin >> vn >> en;

   st = 1;
   Graph g(vn);

   int s, d, w;

   for(int i = 0; i < en; i++) {
      cin >> s >> d >> w;

      g.addEdge(s, d, w);
   }

   bellmanford(g, st);

   return 0;
}
```


### 코드 리뷰 요약:
1. **조기 종료 로직 추가**: 각 반복마다 `isUpdated` 플래그를 사용하여 최단 거리 배열 `sht`의 어떤 값도 업데이트되지 않았다면 루프를 조기 종료합니다. 이는 계산을 상당히 줄여줍니다.
2. **음의 사이클 검출**: 모든 반복이 끝난 후에도 한 번 더 모든 에지를 검사하여, 조건에 따라 음의 가중치 사이클이 존재하는지 확인합니다.
3. **출력**: 각 정점에 대한 최단 거리를 출력하면서, `numeric_limits<int>::max()` 값이면 "INF"로 출력합니다. 이는 해당 정점이 시작 정점에서 도달할 수 없음을 나타냅니다.