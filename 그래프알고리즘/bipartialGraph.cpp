#include <cstdio>
#include <vector>
#include <queue>

std::vector< std::vector<std::pair<int, int> > > mat(10, std::vector<std::pair<int ,int> >(10, std::pair<int, int>()));

void DFS_Recursive(int st, std::vector<std::pair<int, int> >& visited) {

   for(int j = 1; j < 10; j++) {
      if(mat[st][j].first == 1 && 
         visited[j].first == 0
      ) { ///방문하지 않은 정점이라면
         visited[j].first = 1;
         visited[j].second = visited[st].second ? 0 : 1;
         printf("%d\n", visited[j].second);
         DFS_Recursive(j, visited);
      }
   }
}

void BFS(int st, std::vector<std::pair<int, int> > rb) {
   std::vector<int> visited(10);
   visited[st] = 1;
   std::queue<int> q;
   q.push(st);

   while(!q.empty())  {
      int p = q.front();
      q.pop();

      for(int i = 1; i < 10; i++) {
         if(mat[p][i].first == 1 && visited[i] == 0) {
            visited[i] = 1;
            q.push(i);
         }
      }
   }
}

std::vector<std::pair<int, int> > DFS(int st) {
   std::vector<std::pair<int, int> > visited(10);
   ///first: 방문여부, second: 0혹은 1로 표시
   visited[st].first = 1;
   visited[st].second = 0;
   printf("%d\n", visited[st].second);
   DFS_Recursive(st, visited);


   return visited;
}


int main(void) {

   int vertexCount, edgeCount;
   int input[2];
   scanf("%d %d", &vertexCount, &edgeCount);
   
   for(int i = 0; i < edgeCount; i++) {
      for(int j = 0; j < 2; j++) {
         scanf("%d", input + j);
      }

      mat[input[0]][input[1]] = {1, 0};
   }

   std::vector<std::pair<int, int> > bipartial = DFS(1);

   BFS(1, bipartial);
   

   return 0;
}