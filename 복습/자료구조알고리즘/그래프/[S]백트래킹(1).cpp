#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::endl;

int N, M;

void rec(vector<int> visited, vector<int> selected) {
   if(selected.size() == M) {
      for(auto x: selected) {
         cout << x << " ";
      }
      cout << '\n';
      return;
   }

   for(int i = 1; i <= N; ++i) {
      if(!visited[i]) {
         visited[i] = 1;
         selected.push_back(i);
         rec(visited, selected);

         visited[i] = 0;
         selected.pop_back();
      }
   }

}

int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> N >> M;

   rec(vector<int>(N + 1, 0), vector<int>());

   return 0;
}