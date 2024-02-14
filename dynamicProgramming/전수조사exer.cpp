#include <bits/stdc++.h>
using namespace std;

void getAllSubset(vector<int> set, vector<int> subset, int index,
                  vector<vector<vector<int>>>& allSubset
) {
   if(index == set.size()) { ///전부 순회완료
      allSubset[subset.size()].push_back(subset);
      return ;
   }

   getAllSubset(set, subset, index + 1, allSubset);

   subset.push_back(set[index]);
   getAllSubset(set, subset, index + 1, allSubset);
}

bool sol(vector<int> set, int target) {
   vector<vector<vector<int>>> allsubset(set.size() + 1);

   getAllSubset(set, {}, 0, allsubset);
   for(int i = 0; i < set.size(); i++) {
      cout << i << '\n';
      for(auto subset: allsubset[i]) {
         int sum = 0;
         for(auto e: subset) {
            cout << e << " ";
            sum += e;
         }

         if(sum == target) {
            return true;
         }
         cout << '\n';
      }
   }

   return false;
}

int main(void) {
   vector<int> set = {13, 79, 45, 29};
   int target = 58;

   if(sol(set, target)) {
      cout << "합이 58인 부분집합이 존재한다";
   } else {
      cout << "합이 58인 부분집합이 존재하지 않는다.";
   }

   return 0;
}