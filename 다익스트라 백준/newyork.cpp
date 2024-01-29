#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <queue>

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


void dijkstra(int vn, int st, const Graph& G) {
   std::vector<std::pair<int, int>> sht(vn + 1, std::make_pair(std::numeric_limits<int>::max(), -1));
   std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

   sht[st] = std::make_pair(0, st);
   pq.push(std::make_pair(0, st));

   while (!pq.empty()) {
      int mv = pq.top().second;
      pq.pop();
      for (const auto& edge : G.vertices[mv]) {
         if (sht[mv].first != std::numeric_limits<int>::max() && sht[mv].first + edge.weight < sht[edge.dst].first) {
            sht[edge.dst].first = sht[mv].first + edge.weight;
            sht[edge.dst].second = mv;
            pq.push(std::make_pair(sht[edge.dst].first, edge.dst));
         }
      }
   }

   backTracking(st, 542, sht);
}


int main() {
    std::ifstream inputFile("USA-road-d.NY.gr.txt");

    // 파일 열기에 실패했는지 확인
    if (!inputFile.is_open()) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return 1; // 프로그램 종료
    }
   int vn, en;
   inputFile >> vn >> en;
   Graph g(vn + 1);
   int src, dst, weight;
   for(int i = 0; i < en; i++) {
      inputFile.get();
      inputFile.get();
      inputFile >> src >> dst >> weight;
      g.addEdge(src, dst, weight);
      inputFile.get();
   }

   dijkstra(vn, 913, g);

    return 0;
}
