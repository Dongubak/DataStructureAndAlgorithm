#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>

std::vector<std::vector<bool> > mat(100, std::vector<bool>(100));

std::unordered_map<int, std::string> color_map = {
      {1, "Red"},
      {2, "Blue"},
      {3, "Green"},
      {4, "Yellow"},
      {5, "Black"},
      {6, "White"},
};

std::vector<int> greedy_coloring(int n) {
   std::vector<int> assigned_color(n + 1);

   std::vector<std::pair<int, int> > degree(n + 1);

   for(int i = 1; i < n + 1; i++) {
      for(int j = 1; j < n + 1; j++) {
         if(mat[i][j] == 1) {
            degree[i].first = i;
            degree[i].second++;
         }
      }
   }

   sort(degree.begin() + 1, degree.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) {
      if(p1.second == p2.second) {
         return p1.first < p2.first;
      } else {
         return p1.second > p2.second;
      }
   });

   for(auto a : degree) {
      std::set<int> neighbors;

      for(int j = 0; j < n + 1; j++) {
         if(mat[a.first][j] == 1) {
            neighbors.insert(assigned_color[j]);
         }
      }

      int smallest = 1;
      for(; smallest < color_map.size(); smallest++) {
         if(neighbors.find(smallest) == neighbors.end()) {
            break;
         }
      }

      assigned_color[a.first] = smallest;
   }


   return assigned_color;
}


int main(void) {
   using namespace std;

   ///주어진 그래프 g에서 서로 인접한 정점끼리 같은 색을 가지지 않도록 모든 정점에 색상을 지정하는 것
   
   int m, n; ///m은 정점의 개수 n은 간선의 개수
   int l, k;

   cin >> m >> n;

   for(int i = 1; i < n + 1; i++) {
      cin >> l >> k;
      mat[l][k] = true;
   }
   cout << "dfsfsdf" << '\n';

   vector<int> colored = greedy_coloring(m);
   
   for(int i = 1; i < m + 1; i++) {
      cout <<  color_map[colored[i]] << '\n';
   }
   
   

   return 0;
}