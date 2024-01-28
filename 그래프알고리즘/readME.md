## 🧐 dijkstra 알고리즘 최적화

다익스트라 알고리즘은 최단거리표(shortest path table)을 사용하여 모든 정점을 방문하면서 최단거리표를 업데이트한다.

### 🤗 다익스트라 알고리즘의 최단거리표 작성 과정
1. 최단거리표에서 시작정점의 값을 0으로 놓는다.
2. 방문하지 않은 정점들의 집합에서 최단거리표의 값이 가장 작고 방문하지 않은 정점을 고른다. 찾은 정점을 작은 정점이라 하겠다.
3. 작은 정점을 방문하지 않은 정점에서 제거한다.
4. 작은 정점의 인접정점에 대해서 최단거리표를 참고하여 작은 값으로 업데이트한다. (시작 지점부터 작은정점까지 이동할 때 가중치의 합은 최단거리표를 참고할 수 있으며 작은 정점부터 인접정점까지의 가중치는 엣지를 통해 얻을 수 있으며 두 합이 인접정점에 대해 최단거리표 값보다 작다면 업데이트 한다)
5. 방문하지 않은 정점이 없을 때까지 반복한다.

```cpp
#include <cstdio>
#include <vector>
#include <list>

std::vector<std::vector<std::pair<int, int> > > mat(9, std::vector<std::pair<int, int> >(9));

void backTrackingRecursive(int st, int cur, std::vector<std::pair<int, int> > sht) {
   if(cur != st) {
      backTrackingRecursive(st, sht[cur].second, sht);
      printf("%d\n", cur);
   }
}

void backTracking(int st, int end, std::vector<std::pair<int, int> > sht) {
   printf("%d\n", st);
   backTrackingRecursive(st, end, sht);
}


void dijkstra (int vn, int st, int end){
   std::vector<std::pair<int, int> > sht(vn + 1, std::pair<int, int>(10000, -1));
   std::list<int> unvisited;
   
   for(int i = 1; i < vn + 1; i++) {
      unvisited.push_front(i);
   }

   sht[st].first = 0;

   while(!unvisited.empty()) {
      int tmpMin = 100000;
      int mv;
      for(int i = 1; i < vn + 1; i++) {
         if(find(unvisited.begin(), unvisited.end(), i) != unvisited.end() &&
            sht[i].first < tmpMin) {
               tmpMin = sht[i].first;
               mv = i;
            }
      }
      
      unvisited.erase(find(unvisited.begin(), unvisited.end(), mv));

      for(int j = 1; j < vn + 1; j++) {
         if(mat[mv][j].first == 1 && 
            sht[mv].first + mat[mv][j].second < sht[j].first
         ) {
            sht[j].first = sht[mv].first + mat[mv][j].second;
            sht[j].second = mv;
         }
      }
   }


   backTracking(st, end, sht);
}

int main(void) {
   int vn, en; ///vn : 정점의 개수, en : 간선의 개수
   int s, e, w; ///s : 시정점, e : 종정점, w : 가중치

   scanf("%d %d", &vn, &en);

   for(int i = 0; i < en; i++) {
      scanf("%d %d %d", &s, &e, &w);
      mat[s][e].first = 1;
      mat[s][e].second = w;
   }

   dijkstra(vn, 1, 6);

   return 0;
}
```
![Alt text](image.png)


### 🌪️ 다익스트라 알고리즘을 우선순위 큐를 이용하여 최적화 하기
위 다익스트라 알고리즘은 방문하지 않은 정점 중 가장 최단거리표값이 가장 작은 정점을 찾는 과정에서 시간을 잡아먹는다. 따라서 우선순위 큐를 사용하여 업데이트를 했다면 우선순위큐에 추가하는 식으로 최적화 할 수 있다. 종료하는 시점엔 더 이상 최단거리표를 업데이트할 필요가 없다는 것이며, 이는 시작 정점부터 최단거리표가 완성되었다는 것이다.

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>

class Edge {
public:
   int dst;
   int weight;

   Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   std::vector<std::list<Edge>> vertices;

   Graph(int size) {
      vertices.resize(size + 1);
   }

   void addEdge(int src, int dst, int weight) {
      vertices[src].push_back(Edge(dst, weight));
   }
};

void getData(std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq) {
   printf("--------\n");
   while(!pq.empty()) {
      printf("%d %d\n", pq.top().first, pq.top().second);
      pq.pop();
   }
}

void dijkstra(int vn, int st, const Graph& G) {
   std::vector<int> sht(vn + 1, std::numeric_limits<int>::max());
   std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

   sht[st] = 0;
   pq.push(std::make_pair(0, st));

   while (!pq.empty()) {
      getData(pq);
      int mv = pq.top().second;
      pq.pop();
      for (const auto& edge : G.vertices[mv]) {
         if (sht[mv] != std::numeric_limits<int>::max() && sht[mv] + edge.weight < sht[edge.dst]) {
            sht[edge.dst] = sht[mv] + edge.weight;
            pq.push(std::make_pair(sht[edge.dst], edge.dst));
         }
      }
   }

   for (int i = 1; i <= vn; ++i) {
      if (sht[i] != std::numeric_limits<int>::max()) {
         std::cout << sht[i] << "\n";
      } else {
         std::cout << "INF\n";
      }
   }
}

int main() {
   int vn, en, st;
   std::cin >> vn >> en >> st;

   Graph G(vn);

   for (int i = 0; i < en; ++i) {
   int s, e, w;
   std::cin >> s >> e >> w;
   G.addEdge(s, e, w);
   }

   dijkstra(vn, st, G);

   return 0;
}
```
![Alt text](image-1.png)

```cpp
dijkstra(vn, st, G):
   vn: 정점수
   st: 시작정점
   G: 그래프

   shortest_path 초기화 : sht
   priority_queue : pq 최소힙으로 선언

   sht[st] <- 0
   pq = {0, st}

   while(pq is not empty):
      mv <- pq.top.vertex : minimum vertex that sorted by shortest table

      for x ∈ adj(mv):
         if(sht[x] is not lim and sht[mv] + x.weight < sht[x]) {
            sht[x] = sht[mv] + x.weight
            pq <- {sht[x], x}
         }
   
```


## 🥸 그래프 알고리즘2

- 다익스트라 알고리즘의 문제점 확인
- 벨만 포드 알고리즘
- 음수 가중치 사이클
- 존슨 알고리즘
- 코사라주 알고리즘

### 다익스트라 알고리즘의 문제점
다익스트라 알고리즘은 그리디 방식으로 매 그래프를 순회할 때마다 가장 거리가 가까운 정점을 고르며 이미 방문한 정점에 대해서 최단 경로가 결정되어 있다고 가정하므로 음수 가중치가 있는 경우 이미 방문한 경로를 재 탐색하지 않아 최적의 경로를 찾지 못 할 수도 있다.

이 예시에서 각 정점에 대해서 최적의 경로를 골라 그리디 방식으로 검색할 경우

![Alt text](image-3.png)
1. 1번 정점에서 2번정점으로 이동하여 기록한다.
2. 2번 정점에서 3번과 4번으로 이동하여 기록한다.
3. 3번에서 5번으로 이동하여 4번에서 4번으로 이동하지 않는다. (이미 최적의 경로가 설정되었다고 가정하여 검사하지 않는다.)


### 🤠 벨만 포드 알고리즘 수도 코드
```cpp
function BellmanFord(graph, source):
    // 그래프의 정점 수와 간선 수
    vertices = graph.vertices
    edges = graph.edges

    // 최단 거리 배열 초기화
    distance = [∞] * vertices
    distance[source] = 0

    // 간선을 이용한 최단 거리 갱신
    for i in 1 to vertices - 1:
        for each edge in edges:
            u = edge.start
            v = edge.end
            weight = edge.weight
            if distance[u] + weight < distance[v]:
                distance[v] = distance[u] + weight

    // 최단 거리 배열 반환
    return distance
```

### ✍️ 벨만 포드 알고리즘 수도 코드 설명
벨만 포드 알고리즘은 생각보다 단순하다.
다익스트라 알고리즘은 그리디 방식으로 매 탐색마다 최적의 해를 구했다고 가정하여 방문했던 정점에 대해서 조사하지 않는다. 하지만 벨만포드 알고리즘은 방문했던 정점에 대해서 인접한 정점의 거리 값을 작은 값으로 업데이트하면서 최적의 해를 구한다. 음수 가중치가 있는 경우 벨만 포드 알고리즘이 유리해 보인다. 음수 가중치가 없는 경우에는 다익스트라 알고리즘이 유리해보인다.

1. 각 정점에 대한 출발지로부터 최단 거리 배열을 무한대로 초기화하며 시작 정점에 대한 최단 거리값을 0으로 한다.
2. v - 1번 반복하면서 최단 거리값이 기록된 정점의 인접 정점들 까지의 최단 거리를 업데이트한다.
3. v - 1번 반복한 이후에도 업데이트된다면 음수 사이클이 있는 것이다. 이는 다음절에서 설명한다.

#### 🤔 V - 1번 간선을 검사하는 이유에 대해서
정점의 개수가 v개 일때 사이클을 거치지 않고 시작 정점으로 부터 임의의 정점으로 이동한다면 최대 v - 1번 이동할 수 있다.

### 🤖 벨만 포드 알고리즘 구현
```cpp
#include <cstdio>
#include <vector>
#include <list>
#include <numeric>

class Edge {
public:
   int dst;
   int weight;

   Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   int size;
   std::vector<std::list<Edge>> G;

   Graph(int s) : size(s) {
      G.resize(s);
   }

   void addEdge(int s, int d, int w) {
      G[s].push_back(Edge(d, w));
   }
};

void bellmanFord(Graph& g) {
   std::vector<int> distance(g.size, std::numeric_limits<int>::max());
   distance[1] = 0;
   for(int j = 0; j < g.size - 2; j++) {
      for(int i = 1; i < g.size; i++) {
         for(auto& e : g.G[i]) {
            if(distance[i] != std::numeric_limits<int>::max() &&
               distance[i] + e.weight < distance[e.dst]
            ) {
               distance[e.dst] = distance[i] + e.weight;
            }
         }
      }
   }

   for(int i = 1; i < g.size; i++) {
      printf("%d : %d\n", i, distance[i]);
   }
}

int main(void) {
   using namespace std;

   Graph g(6);
   g.addEdge(1, 2, 3);
   g.addEdge(2, 3, 5);
   g.addEdge(2, 4, 10);
   g.addEdge(4, 3, -7);
   g.addEdge(3, 5 , 2);


   bellmanFord(g);

   return 0;
}
```
### 출력

![Alt text](image-4.png)

### ☠️ 음수 사이클
아래 예시에서 A->B 거리는 3이다. 하지만 B->C->B사이클을 거치면 -2가 감소한 1이 되며 한번 더 사이클을 거치면 -1이 되어 거리값이 무한정으로 감소한다. 이를 파악하는 과정은 생각보다 쉽다. V개의 정점이 있을 때 임의의 정점에서 임의의 정점으로 가장 많이 거쳐 가는 경우는 v-1로 정해져 있다. 따라서 벨만 포드에서 v-1번 검사한 후 최단 거리가 얻어지는 데 음수 사이클이 있는 경우 그 이후에도 사이클을 거쳐 최단 거리가 갱신 된다. 이를 이용하여 v-1번 돌고 한번 더 돌아서 갱신이 되는 지 확인한 후 갱신이 된다면 음수 사이클이 발생한다는 것을 확인할 수 있을 것이다.
![Alt text](image-5.png)



### 👊 음수 사이클 검사
```cpp
// 음수 사이클 검사
    for each edge in edges:
        u = edge.start
        v = edge.end
        weight = edge.weight
        if distance[u] + weight < distance[v]:
            // 음수 사이클이 존재함
            return "음수 사이클이 존재합니다."
```

## 🍰 음수 사이클 검사 코드 구현
```cpp
#include <cstdio>
#include <vector>
#include <list>
#include <numeric>

class Edge {
public:
   int dst;
   int weight;

   Edge(int d, int w) : dst(d), weight(w) {}
};

class Graph {
public:
   int size;
   std::vector<std::list<Edge>> G;

   Graph(int s) : size(s) {
      G.resize(s);
   }

   void addEdge(int s, int d, int w) {
      G[s].push_back(Edge(d, w));
   }
};

void bellmanFord(Graph& g) {
   std::vector<int> distance(g.size, std::numeric_limits<int>::max());
   distance[1] = 0;
   for(int j = 0; j < g.size - 2; j++) {
      for(int i = 1; i < g.size; i++) {
         for(auto& e : g.G[i]) {
            if(distance[i] != std::numeric_limits<int>::max() &&
               distance[i] + e.weight < distance[e.dst]
            ) {
               distance[e.dst] = distance[i] + e.weight;
            }
         }
      }
   }

   bool isCycled = false;

   for(int i = 1; i < g.size; i++) {
      for(auto& e : g.G[i]) {
         if(distance[i] != std::numeric_limits<int>::max() &&
            distance[i] + e.weight < distance[e.dst]
         ) {
            isCycled = true;
            break;
         }
      }
      if(isCycled) {
         break;
      }
   }
   
   if(isCycled) {
      printf("음수 사이클 존재!");
   } else {
      for(int i = 1; i < g.size; i++) {
         printf("%d : %d\n", i, distance[i]);
      }
   }
}

int main(void) {
   using namespace std;

   Graph g1(6);
   g1.addEdge(1, 2, 3);
   g1.addEdge(2, 3, 5);
   g1.addEdge(2, 4, 10);
   g1.addEdge(4, 3, -7);
   g1.addEdge(3, 5 , 2);


   bellmanFord(g1);

   Graph g2(7);
   g2.addEdge(1, 2, 3);
   g2.addEdge(2, 4, -8);
   g2.addEdge(3, 2, 3);
   g2.addEdge(4, 3, 3);
   g2.addEdge(3, 5, 2);
   g2.addEdge(5, 6, -1);
   g2.addEdge(6, 2, 8);

   bellmanFord(g2);

   return 0;
}
```
첫번째 그래프
![Alt text](image-3.png)
이 그래프에서는 최단 거리값이 v-1번 조사한 후에 변함이 없으므로 음수 사이클이 존재하지 않는다.

두번째 그래프
![Alt text](image-5.png)

정점 2는 v-1번 조사한 후에도 최단 거리값이 감소하므로 이는 음수 사이클이 존재한다고 할 수 있다.