## 🧐 dijkstra 알고리즘 최적화

다익스트라 알고리즘은 최단거리표(shortest path table)을 사용하여 모든 정점을 방문하면서 최단거리표를 업데이트한다.

### 다익스트라 알고리즘의 최단거리표 작성 과정
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


### 다익스트라 알고리즘을 우선순위 큐를 이용하여 최적화 하기
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

```
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