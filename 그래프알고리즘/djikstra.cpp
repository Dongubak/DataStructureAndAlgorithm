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