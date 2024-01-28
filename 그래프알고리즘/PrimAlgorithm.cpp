#include <iostream>
#include <vector>
#include <queue>


using namespace std;

// 그래프의 간선을 나타내는 구조체
struct Edge {
    int to, weight;
};

// 프림 알고리즘을 사용하여 최소 신장 트리를 구하고 MST에 추가하는 함수
void prim(vector<vector<Edge>>& graph, int n) {
    vector<bool> visited(n + 1, false);  // 정점 방문 여부를 나타내는 배열
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // 최소 힙

    // 시작 정점을 1로 설정 (임의의 시작 정점 선택)
    int startNode = 1;
    visited[startNode] = true;

    // 시작 정점과 연결된 간선들을 우선순위 큐에 삽입
    for (const Edge& edge : graph[startNode]) {
        pq.push({edge.weight, edge.to});
    }

    int minCost = 0;  // 최소 신장 트리의 가중치 합

    cout << "MST에 추가되는 간선 정보:\n";

    while (!pq.empty()) {
        int weight = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // 이미 방문한 정점이면 스킵
        if (visited[currentNode]) {
            continue;
        }

        // 해당 정점을 방문하고 가중치를 더함
        visited[currentNode] = true;
        minCost += weight;

        // 현재 간선을 MST에 추가하는 과정 출력
        if (currentNode != startNode) {
            cout << "간선 추가: " << startNode << " - " << currentNode << " (가중치: " << weight << ")\n";
        }

        // 연결된 간선들을 우선순위 큐에 삽입
        for (const Edge& edge : graph[currentNode]) {
            if (!visited[edge.to]) {
                pq.push({edge.weight, edge.to});
            }
        }
    }

    // 결과 출력
    cout << "최소 신장 트리의 가중치 합: " << minCost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;  // 정점의 수와 간선의 수 입력

    vector<vector<Edge>> graph(n + 1);  // 그래프 초기화

    // 간선 정보 입력
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    // 프림 알고리즘 호출
    prim(graph, n);

    return 0;
}
