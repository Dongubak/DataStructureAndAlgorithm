#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> table(4 + 1);

void recur(vector<int>& set, int ind, vector<int> sub) {
   if(ind == 4) {
      table[sub.size()].push_back(sub);
      cout << "추가된 부분집합 : " << '\n';
      for(auto ele: sub) {
         cout << ele << " ";
      }
      cout << '\n';
      return;
   }
   
   recur(set, ind + 1, sub);
   sub.push_back(set[ind]);
   recur(set, ind + 1, sub);
}

/*
   전수 조사방식에서 백트래킹방식으로 최적화 할 때
   기저 조건을 수정함 (ind == set.size() or sum of subset > target) false반환

   2차원 배열에서 
*/

void sol(vector<int>& set) {
   recur(set, 0, {});
}

int main(void) {

   vector<int> set = {1, 3, 7, 11};
   sol(set);

   for(int size = 0; size < set.size() + 1; size++) {
      for(auto subsets : table[size]) {
         for(auto subset : subsets) {
            cout << subset << " ";
         }
         cout << '\n';
      }
   }
}